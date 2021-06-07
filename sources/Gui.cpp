#include <stdafx.h>
#include <Gui.h>
#include <qlistwidget.h>

GUI::GUI(int width, int height) :
	ui(new Ui::MainWindow())
{
	ui->setupUi(this);
	connect(ui->searchUserComboBox->lineEdit(), &QLineEdit::textChanged, this, &GUI::onSearchComboBoxTextChanged);
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
}

void GUI::onSearchComboBoxTextChanged(const QString& text)
{
}