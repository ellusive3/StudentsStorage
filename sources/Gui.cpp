#include <stdafx.h>
#include <Gui.h>
#include <qlistwidget.h>
#include <qlabel.h>
#include <qtableview.h>
#include <qpainter.h>
#include <qstandarditemmodel.h>
#include <qfontmetrics.h>
#include <qmessagebox.h>
#include <qpixmap.h>

THeaderView::THeaderView(Qt::Orientation orientation, QWidget* parent) :
	QHeaderView(orientation, parent),
	_font(QFont("helvetica", 15)),
	_metrics(_font)
{
	this->_descent = this->_metrics.descent();
	this->_margin = 10;
}

void THeaderView::paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const
{
	auto data = this->model()->headerData(logicalIndex, this->orientation());
	painter->rotate(90);
	painter->setFont(this->font());
	painter->drawText(-rect.height() + this->_margin,
		rect.left() + (rect.width() + this->_descent) / 2, data.toString());
}

GUI::GUI(int width, int height) :
	ui(new Ui::MainWindow())
{
	ui->setupUi(this);
	connect(ui->searchStudentBtn, &QPushButton::clicked, this, &GUI::onSearchUserButtonClicked);
	connect(ui->listSection, &QListWidget::itemClicked, this, &GUI::onSectionClicked);
	//connect(ui->searchUserComboBox, &QComboBox::currentTextChanged, this, &GUI::onSearchComboBoxTextChanged);
	connect(ui->openAddStudentForm, &QPushButton::clicked, this, &GUI::onOpenAddStudentForm);
	this->setBaseSize(QSize(width, height));
	this->show();
	userId = -1;
	objectId = -1;
}

GUI::~GUI()
{
}

void GUI::ClearLayout(QLayout * layout) {
	QLayoutItem* item;
	while ((item = layout->takeAt(0))) {
		if (item->layout()) {
			this->ClearLayout(item->layout());
			delete item->layout();
		}
		if (item->widget()) {
			delete item->widget();
		}
		delete item;
	}
	userId = -1;
	objectId = -1;
}


void GUI::PrintUserInfo(const User& printedUser)
{
	this->ClearLayout(dynamic_cast<QLayout*>(ui->dynamicContentLayout));
	userId = printedUser.GetUserId();
	QLabel* userNameLabel = new QLabel(this);
	std::string studentFullName = "Student: " + printedUser.GetLastName() + " " + printedUser.GetFirstName() + " " + printedUser.GetThirdName();
	userNameLabel->setText(QString(studentFullName.c_str()));
	userNameLabel->setVisible(true);
	QLabel* avgDiscMark = new QLabel(this);
	avgDiscMark->setText(QString("Average discipline score: ") + QString::number(printedUser.GetAvgDisciplineScore()));
	avgDiscMark->setVisible(true);

	std::vector<IntStringStruct> groups;
	if (!GetGroupsSignal.empty())
		groups = GetGroupsSignal();
	std::string groupStr = "Group: ";
	for (auto group : groups) {
		if (group.id == printedUser.GetGroupId()) {
			groupStr += group.groupName;
			break;
		}
	}
	QLabel* groupLabel = new QLabel(this);
	groupLabel->setText(QString(groupStr.c_str()));
	groupLabel->setVisible(true);

	QTableView* view = new QTableView(this);
	THeaderView mHeader(Qt::Horizontal);
	//view->setHorizontalHeader(&mHeader);
	view->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
	view->setVisible(true);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	QStandardItemModel* model = new QStandardItemModel(this);
	int currentCol = 0;
	model->insertRows(0, 1);
	model->insertColumns(currentCol, 1);
	view->setModel(model);
#pragma region  LambdaExpression
	connect(view->selectionModel(), &QItemSelectionModel::selectionChanged, this, [model, this, printedUser](const QItemSelection& selected, const QItemSelection& deselected) {
		int rowsCount = model->rowCount();
		int selectedRowsCount = 0;
		std::vector<bool> alreadySelected = std::vector<bool>(rowsCount);
		for (auto& index : selected.indexes()) {
			if (!alreadySelected[index.row()]) {
				alreadySelected[index.row()] = true;
				selectedRowsCount++;
			}
		}
		printf("Selected rows %d", selectedRowsCount);
		if (selectedRowsCount == 1) {
			int selectedRow = selected.indexes().begin()->row();
			if (!FindUserMarksSignal.empty()) {
				MarkList marks = FindUserMarksSignal(printedUser.GetUserId());
				for (auto mark : marks) {
					if (mark.second.first == model->data(model->index(selectedRow, 0), Qt::DisplayRole).toString().toStdString()) {
						objectId = mark.first;
						break;
					}
				}
			}
		}
		else
			objectId = -1;
		});
#pragma endregion

	model->setHeaderData(currentCol++, Qt::Horizontal, QObject::tr("Object/Mark"), Qt::DisplayRole);

	if (!FindUserMarksSignal.empty() && !GetObjectsSignal.empty()) {
		MarkList marks = FindUserMarksSignal(printedUser.GetUserId());
		for (auto mark : marks) {
			auto indexList = model->match(model->index(1, 0), Qt::DisplayRole, tr(mark.second.first.c_str()));
			QModelIndex objectIndex;
			if (indexList.empty()) {
				// Если нет еще такого предмета в таблице, то добавим его, иначе просто проставим оценку в нужной дате
				int currentRow = model->rowCount() - 1;
				model->insertRows(currentRow, 1);
				objectIndex = model->index(currentRow, 0);
				model->setData(objectIndex, tr(mark.second.first.c_str()));
			}
			else {
				// Такой предмет уже есть в таблице, запомним его индекс
				objectIndex = indexList.at(0);
			}
			// На этом моменте у нас полюбому есть индекс строки с предметом
			// Из текущей оценки возьмем дату, попробуем найти существующую колонку
			int neededIndex = -1;
			for (int colIndex = 0; colIndex < model->columnCount(); colIndex++) {
				tm timeStamp = boost::posix_time::to_tm(mark.second.second.first);
				std::string markDate = std::to_string(timeStamp.tm_mday) + "." + std::to_string(timeStamp.tm_mon + 1) + "." + std::to_string(timeStamp.tm_year + 1900);
				if (model->headerData(colIndex, Qt::Horizontal, Qt::DisplayRole).toString() == markDate.c_str()) {
					neededIndex = colIndex;
					break;
				}
			}
			if (neededIndex == -1) {
				tm timeStamp = boost::posix_time::to_tm(mark.second.second.first);
				std::string markDate = std::to_string(timeStamp.tm_mday) + "." + std::to_string(timeStamp.tm_mon + 1) + "." + std::to_string(timeStamp.tm_year + 1900);
				model->insertColumns(currentCol, 1);
				model->setHeaderData(currentCol, Qt::Horizontal, QObject::tr(markDate.c_str()));
				neededIndex = currentCol++;
			}
			QModelIndex addingMarkIndex = model->index(objectIndex.row(), neededIndex);
			model->setData(addingMarkIndex, QString::number(mark.second.second.second));
			model->setData(addingMarkIndex, Qt::AlignCenter, Qt::TextAlignmentRole);
		}
	}

	QPushButton* addMarkButton = new QPushButton(this);
	std::string currentPath = boost::filesystem::current_path().generic_string() + "/plus_icon.ico";
	QPixmap buttonPic(currentPath.c_str());
	addMarkButton->setIcon(buttonPic);
	addMarkButton->setFixedWidth(50);
	connect(addMarkButton, &QPushButton::clicked, this, &GUI::onOpenAddMarkForm);

	ui->dynamicContentLayout->addWidget(userNameLabel);
	ui->dynamicContentLayout->addWidget(groupLabel);
	ui->dynamicContentLayout->addWidget(avgDiscMark);
	ui->dynamicContentLayout->addWidget(addMarkButton);
	ui->dynamicContentLayout->addWidget(view);
}

void GUI::PrintCity(const City& _city)
{
}

void GUI::PrintEvents(const std::vector<Event>& events)
{

}

void GUI::onSearchComboBoxTextChanged(const QString& text)
{
}

void GUI::onSectionClicked(QListWidgetItem* item)
{
	ClearLayout(ui->dynamicContentLayout);
}

void GUI::onSearchUserButtonClicked()
{
	std::string userStr = ui->searchUserComboBox->currentText().toStdString();
	if (!FindUserSignal.empty()) {
		QStringList userSplitted = ui->searchUserComboBox->currentText().split(" ", QString::KeepEmptyParts,Qt::CaseSensitivity::CaseInsensitive);
		if (userSplitted.size() > 1) {
			std::string firstName = userSplitted[0].toStdString();
			std::string lastName = userSplitted[1].toStdString();
			User user = FindUserSignal(firstName, lastName);
			PrintUserInfo(user);
		}
	}
	// TODO вернуть ошибку, что формат введенных данных был неверен
}

void GUI::CompleteUsers()
{
	if (!FindUsersSignal.empty())
	{
		std::vector<UserInfo> userInfo = FindUsersSignal("");

		for (auto user : userInfo)
		{
			//this->blockSignals(true);
			std::string resultStr = user.second.first + " " + user.second.second;
			ui->searchUserComboBox->addItem(tr(resultStr.c_str()));
		}
	}
}

// Klepko A.Y.
void GUI::onOpenAddStudentForm()
{
	if (!GetGroupsSignal.empty() && !AddUserSignal.empty())
	{
		std::vector<IntStringStruct> groups = GetGroupsSignal();
		AddUserDialog* dlg = new AddUserDialog(groups);

		int result = dlg->exec();
		if (result == QDialog::Accepted) {
			// Добавляем пользователя в БД
			int addRes = AddUserSignal(dlg->GetFirstName(), dlg->GetLastName(), dlg->GetThirdName(), dlg->GetGroupId());
			if (addRes == ERROR_USER_ALREADY_EXIST) {
				QMessageBox errorMessage(QMessageBox::Icon::Warning,
					QString::fromStdWString(L"Ошибка при добавлении нового пользователя"),
					QString::fromStdWString(L"При добавлении пользователя возникла ошибка. Указанный пользователь уже существует!"),
					QMessageBox::Ok,
					this);
				errorMessage.exec();
			}
			else if (addRes == ERROR_UNKNOWN_ERROR) {
				QMessageBox errorMessage(QMessageBox::Icon::Critical,
					QString::fromStdWString(L"Ошибка при добавлении нового пользователя"),
					QString::fromStdWString(L"При добавлении пользователя возникла ошибка. Информация об ошибке недоступна"),
					QMessageBox::Ok,
					this);
				errorMessage.exec();
			}
		}
	}
}

void GUI::onOpenAddMarkForm()
{
	if (userId > -1 && objectId > -1) {
		AddMarkDialog* markForm = new AddMarkDialog();
		int result = markForm->exec();
		if (result == QDialog::Accepted) {
			uint64_t markValue = markForm->GetMarkValue();
			QDate markDate = markForm->GetMarkDate();
			if (!AddMarkSignal.empty()) {
				std::string qtDateStr = std::to_string(markDate.year()) + "-" + std::to_string(markDate.month()) + "-" + std::to_string(markDate.day());
				boost::posix_time::ptime boostTime = boost::posix_time::time_from_string(qtDateStr + " 00:00:00");
				AddMarkSignal(userId, objectId, Mark(boostTime, markValue));
				ui->searchStudentBtn->click();
			}
		}
	}
	else {
		QMessageBox errorMessage(QMessageBox::Icon::Critical,
			QString::fromStdWString(L"Ошибка при добавлении оценки пользователю"),
			QString::fromStdWString(L"Пожалуйста, выберите пользователя и выделите строку с предметом из таблицы оценок!"),
			QMessageBox::Ok,
			this);
		errorMessage.exec();
	}
}

