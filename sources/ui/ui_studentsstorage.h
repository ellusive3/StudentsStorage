/********************************************************************************
** Form generated from reading UI file 'Student_Storage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTSSTORAGE_H
#define UI_STUDENTSSTORAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchSectionLineEdit;
    QPushButton *searchSectionBtn;
    QListWidget *listSection;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *searchStudentLineEdit;
    QPushButton *searchStudentBtn;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1116, 785);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QLatin1String(".verticalLayout_4 {\n"
"	width: 300px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 271, 731));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        searchSectionLineEdit = new QLineEdit(verticalLayoutWidget_2);
        searchSectionLineEdit->setObjectName(QStringLiteral("searchSectionLineEdit"));

        horizontalLayout->addWidget(searchSectionLineEdit);

        searchSectionBtn = new QPushButton(verticalLayoutWidget_2);
        searchSectionBtn->setObjectName(QStringLiteral("searchSectionBtn"));

        horizontalLayout->addWidget(searchSectionBtn);


        verticalLayout_4->addLayout(horizontalLayout);

        listSection = new QListWidget(verticalLayoutWidget_2);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listSection);
        __qlistwidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listSection);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listSection);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        new QListWidgetItem(listSection);
        listSection->setObjectName(QStringLiteral("listSection"));
        QFont font;
        font.setPointSize(19);
        listSection->setFont(font);
        listSection->setAutoFillBackground(false);
        listSection->setStyleSheet(QLatin1String("background-color: #5086D7;\n"
"color: #fff;\n"
"margin-top: -20px;"));

        verticalLayout_4->addWidget(listSection);


        verticalLayout_6->addLayout(verticalLayout_4);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(310, 10, 216, 25));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchStudentLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        searchStudentLineEdit->setObjectName(QStringLiteral("searchStudentLineEdit"));

        horizontalLayout_3->addWidget(searchStudentLineEdit);

        searchStudentBtn = new QPushButton(horizontalLayoutWidget_2);
        searchStudentBtn->setObjectName(QStringLiteral("searchStudentBtn"));

        horizontalLayout_3->addWidget(searchStudentBtn);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(310, 50, 781, 691));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1116, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        searchSectionLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\262\320\260\320\275\320\270\320\265 \321\200\320\260\320\267\320\264\320\265\320\273\320\260", Q_NULLPTR));
        searchSectionBtn->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", Q_NULLPTR));

        const bool __sortingEnabled = listSection->isSortingEnabled();
        listSection->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listSection->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "\320\243\321\207\320\265\320\261\320\260", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listSection->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\320\265\321\210\320\265\321\201\321\202\320\262\320\270\321\217", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listSection->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "\320\241\321\201\321\213\320\273\320\272\320\270 \320\264\320\273\321\217 \321\203\321\207\320\265\320\261\321\213", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = listSection->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "\320\226\320\270\320\267\320\275\321\214 \320\270\320\275\321\201\321\202\320\270\321\202\321\203\321\202\320\260", Q_NULLPTR));
        listSection->setSortingEnabled(__sortingEnabled);

        searchStudentLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", Q_NULLPTR));
        searchStudentBtn->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTSSTORAGE_H
