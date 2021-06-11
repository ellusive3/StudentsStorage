#include <AddMarkDialog.h>

AddMarkDialog::AddMarkDialog() :
	dlg(new Ui::MarkDialog())
{
	dlg->setupUi(this);
	connect(dlg->closeMarkDialog, &QPushButton::clicked, this, &AddMarkDialog::onCloseButtonClicked);
	connect(dlg->addMark, &QPushButton::clicked, this, &AddMarkDialog::onAddButtonClicked);
}

void AddMarkDialog::onCloseButtonClicked()
{
	reject();
}

void AddMarkDialog::onAddButtonClicked()
{
	markDate = dlg->markDateDateEdit->date();
	markValue = (uint64_t) dlg->markValueSpinBox->value();
	accept();
}

uint64_t AddMarkDialog::GetMarkValue() const
{
	return markValue;
}

QDate AddMarkDialog::GetMarkDate() const
{
	return markDate;
}