#include <stdafx.h>
#include <Gui.h>
#include <qlistwidget.h>
#include <qlabel.h>
#include <qtableview.h>
#include <qpainter.h>
#include <qstandarditemmodel.h>
#include <qfontmetrics.h>

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
	this->setBaseSize(QSize(width, height));
	this->show();
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
}


void GUI::PrintUserInfo(const User& printedUser)
{
	this->ClearLayout(dynamic_cast<QLayout*>(ui->dynamicContentLayout));
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

	ui->dynamicContentLayout->addWidget(userNameLabel);
	ui->dynamicContentLayout->addWidget(groupLabel);
	ui->dynamicContentLayout->addWidget(avgDiscMark);
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
