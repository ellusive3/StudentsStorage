/********************************************************************************
** Form generated from reading UI file 'Student_Storage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_STORAGE_H
#define UI_STUDENT_STORAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *dynamicContentLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *searchUserComboBox;
    QPushButton *searchStudentBtn;
    QFrame *line;
    QPushButton *openAddStudentForm;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1116, 785);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setAutoFillBackground(false);
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

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(310, 50, 781, 691));
        dynamicContentLayout = new QVBoxLayout(verticalLayoutWidget_3);
        dynamicContentLayout->setObjectName(QStringLiteral("dynamicContentLayout"));
        dynamicContentLayout->setSizeConstraint(QLayout::SetNoConstraint);
        dynamicContentLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(310, 10, 431, 29));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        searchUserComboBox = new QComboBox(widget);
        searchUserComboBox->setObjectName(QStringLiteral("searchUserComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchUserComboBox->sizePolicy().hasHeightForWidth());
        searchUserComboBox->setSizePolicy(sizePolicy);
        searchUserComboBox->setInputMethodHints(Qt::ImhNone);
        searchUserComboBox->setEditable(true);
        searchUserComboBox->setFrame(true);

        horizontalLayout_3->addWidget(searchUserComboBox);

        searchStudentBtn = new QPushButton(widget);
        searchStudentBtn->setObjectName(QStringLiteral("searchStudentBtn"));

        horizontalLayout_3->addWidget(searchStudentBtn);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        openAddStudentForm = new QPushButton(widget);
        openAddStudentForm->setObjectName(QStringLiteral("openAddStudentForm"));

        horizontalLayout_4->addWidget(openAddStudentForm);

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

        searchUserComboBox->setProperty("placeholderText", QVariant(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\275\320\270\321\202\320\265 \320\262\320\262\320\276\320\264\320\270\321\202\321\214 \320\270\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", Q_NULLPTR)));
        searchStudentBtn->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", Q_NULLPTR));
        openAddStudentForm->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_STORAGE_H
