#include <stdafx.h>
#include <AddUserDialog.h>

AddUserDialog::AddUserDialog(std::vector<IntStringStruct> _groups) :
	dlg(new Ui::Dialog())
{
	for (auto group : _groups) {
		groups.insert(std::make_pair(group.groupName, group.id));
	}
	dlg->setupUi(this);
	for (auto group : groups) {
		dlg->studenGroupComboBox->addItem(tr(group.first.c_str()));
	}
	connect(dlg->addNewStudentBtn, &QPushButton::clicked, this, &AddUserDialog::onAddNewUserButtonClicked);
}

void AddUserDialog::onAddNewUserButtonClicked()
{
	firstName = dlg->firstNameLineEdit->text().toStdString();
	lastName = dlg->lastNameLineEdit->text().toStdString();
	thirdName = dlg->thirdNameLineEdit->text().toStdString();
	groupId = groups[dlg->studenGroupComboBox->currentText().toStdString()];
	accept();
}

std::string AddUserDialog::GetFirstName() const
{
	return firstName;
}

std::string AddUserDialog::GetLastName() const
{
	return lastName;
}

std::string AddUserDialog::GetThirdName() const
{
	return thirdName;
}

int AddUserDialog::GetGroupId() const
{
	return groupId;
}