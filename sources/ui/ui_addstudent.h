/********************************************************************************
** Form generated from reading UI file 'add_student_form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_STUDENT_FORM_H
#define UI_ADD_STUDENT_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QLabel *addTitle;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lastNameLabel;
    QLineEdit *lastNameLineEdit;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineEdit;
    QLabel *thirdNameLabel;
    QLineEdit *thirdNameLineEdit;
    QFrame *line;
    QLabel *studentGroupLabel;
    QComboBox *studenGroupComboBox;
    QPushButton *addNewStudentBtn;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        Dialog->setMinimumSize(QSize(400, 0));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 20, 271, 251));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        addTitle = new QLabel(widget);
        addTitle->setObjectName(QStringLiteral("addTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addTitle->sizePolicy().hasHeightForWidth());
        addTitle->setSizePolicy(sizePolicy);
        addTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(addTitle);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lastNameLabel = new QLabel(widget);
        lastNameLabel->setObjectName(QStringLiteral("lastNameLabel"));

        verticalLayout->addWidget(lastNameLabel);

        lastNameLineEdit = new QLineEdit(widget);
        lastNameLineEdit->setObjectName(QStringLiteral("lastNameLineEdit"));

        verticalLayout->addWidget(lastNameLineEdit);

        firstNameLabel = new QLabel(widget);
        firstNameLabel->setObjectName(QStringLiteral("firstNameLabel"));

        verticalLayout->addWidget(firstNameLabel);

        firstNameLineEdit = new QLineEdit(widget);
        firstNameLineEdit->setObjectName(QStringLiteral("firstNameLineEdit"));

        verticalLayout->addWidget(firstNameLineEdit);

        thirdNameLabel = new QLabel(widget);
        thirdNameLabel->setObjectName(QStringLiteral("thirdNameLabel"));

        verticalLayout->addWidget(thirdNameLabel);

        thirdNameLineEdit = new QLineEdit(widget);
        thirdNameLineEdit->setObjectName(QStringLiteral("thirdNameLineEdit"));

        verticalLayout->addWidget(thirdNameLineEdit);


        verticalLayout_2->addLayout(verticalLayout);

        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        studentGroupLabel = new QLabel(widget);
        studentGroupLabel->setObjectName(QStringLiteral("studentGroupLabel"));

        verticalLayout_2->addWidget(studentGroupLabel);

        studenGroupComboBox = new QComboBox(widget);
        studenGroupComboBox->setObjectName(QStringLiteral("studenGroupComboBox"));

        verticalLayout_2->addWidget(studenGroupComboBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        addNewStudentBtn = new QPushButton(widget);
        addNewStudentBtn->setObjectName(QStringLiteral("addNewStudentBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addNewStudentBtn->sizePolicy().hasHeightForWidth());
        addNewStudentBtn->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(addNewStudentBtn);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\320\276\320\263\320\276 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", Q_NULLPTR));
        addTitle->setText(QApplication::translate("Dialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\320\276\320\263\320\276 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", Q_NULLPTR));
        lastNameLabel->setText(QApplication::translate("Dialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        firstNameLabel->setText(QApplication::translate("Dialog", "\320\230\320\274\321\217", Q_NULLPTR));
        thirdNameLabel->setText(QApplication::translate("Dialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        studentGroupLabel->setText(QApplication::translate("Dialog", "\320\223\321\200\321\203\320\277\320\277\320\260", Q_NULLPTR));
        addNewStudentBtn->setText(QApplication::translate("Dialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi
        
};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_STUDENT_FORM_H
