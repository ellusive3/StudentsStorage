#include <stdafx.h>
#include <Gui.h>

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

void GUI::PrintUserInfo(const User& printedUser)
{
}

void GUI::PrintCity(const City& _city)
{
}

void GUI::PrintEvents(const std::vector<Event>& events)
{

}

void GUI::onSearchUserButtonClicked()
{
	std::string searchQuery = ui->searchStudentLineEdit->text().toStdString();
	if (!FindUsersSignal.empty())
		FindUsersSignal(searchQuery);
}
