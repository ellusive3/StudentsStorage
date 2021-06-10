#pragma once

#include <IGui.h>
#include <QMainWindow>
#include <QWidget>
#include <qheaderview.h>
#include <ui_studentsstorage.h>
#include <ui_addstudent.h>
#include <User.h>

class THeaderView : public QHeaderView {
	public:
		THeaderView(Qt::Orientation orientation, QWidget* parent = Q_NULLPTR);
		void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const override;
	private:
		QFont _font;
		QFontMetrics _metrics;
		int _descent;
		int _margin;
};


class GUI : public IGui, public QMainWindow, public Ui::MainWindow {
	public:
		GUI(int width, int height);
		~GUI();
		virtual void PrintUserInfo(const User& printedUser) override;
		virtual void PrintCity(const City& _city) override;
		virtual void PrintEvents(const std::vector<Event>& events) override;
		virtual void CompleteUsers() override;
		virtual void CompleteGroups() override;
	private:
		Ui::MainWindow* ui;
		//Klepko A.Y.
		Ui::Dialog* dlg;
		// End Klepko
		void ClearLayout(QLayout* layout);
	protected:
		void onSearchComboBoxTextChanged(const QString& text);
		void onSearchUserButtonClicked();
		void onSectionClicked(QListWidgetItem* item);
		void onOpenAddStudentForm();
};