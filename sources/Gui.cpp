#include <stdafx.h>
#include <Gui.h>
#include <qlistwidget.h>
#include <qlabel.h>

GUI::GUI(int width, int height) :
	ui(new Ui::MainWindow())
{
	ui->setupUi(this);
	connect(ui->searchStudentBtn, &QPushButton::clicked, this, &GUI::onSearchUserButtonClicked);
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


	ui->dynamicContentLayout->addWidget(userNameLabel);
	ui->dynamicContentLayout->addWidget(groupLabel);
	ui->dynamicContentLayout->addWidget(avgDiscMark);
	//TODO отрисовать пользователя на форме
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
