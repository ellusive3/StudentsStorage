#pragma once 
#include <QDialog>
#include <add_mark_form.h>

class AddMarkDialog : public QDialog, public Ui::MarkDialog
{
	public:
		AddMarkDialog();
		uint64_t GetMarkValue() const;
		QDate GetMarkDate() const;
	protected:
	private:
		Ui::MarkDialog* dlg;
		void onCloseButtonClicked();
		void onAddButtonClicked();
		QDate markDate;
		uint64_t markValue;
};