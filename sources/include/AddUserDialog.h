#pragma once

#include <stdafx.h>
#include <QDialog>
#include <ui_addstudent.h>

class AddUserDialog : public QDialog, public Ui::Dialog
{
	public:
		AddUserDialog(std::vector<IntStringStruct> _groups);
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetThirdName() const;
		int GetGroupId() const;
	protected:
	private:
		Ui::Dialog* dlg;
		void onAddNewUserButtonClicked();
		std::string firstName;
		std::string lastName;
		std::string thirdName;
		int groupId;
		std::map<std::string, int> groups;
};