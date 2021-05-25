#pragma once

#include <IGui.h>
#include <QMainWindow>
#include <QWidget>
#include <ui_studentsstorage.h>


class GUI : public IGui, public QMainWindow, public Ui::MainWindow {
	public:
		GUI(int width, int height);
		~GUI();
		virtual void PrintUserInfo(const User& printedUser) override;
		virtual void PrintCity(const City& _city) override;
		virtual void PrintEvents(const std::vector<Event>& events) override;
	private:
		Ui::MainWindow* ui;
	protected:
		void onSearchUserButtonClicked();
};