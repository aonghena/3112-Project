/********************************************************************************
** Form generated from reading UI file 'taskwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWINDOW_H
#define UI_TASKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *title;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QSpinBox *priority;
    QLabel *label_4;
    QTextEdit *description;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *TaskWindow)
    {
        if (TaskWindow->objectName().isEmpty())
            TaskWindow->setObjectName(QString::fromUtf8("TaskWindow"));
        TaskWindow->resize(394, 365);
        horizontalLayout = new QHBoxLayout(TaskWindow);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(TaskWindow);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(TaskWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        title = new QLineEdit(TaskWindow);
        title->setObjectName(QString::fromUtf8("title"));

        horizontalLayout_4->addWidget(title);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(TaskWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        priority = new QSpinBox(TaskWindow);
        priority->setObjectName(QString::fromUtf8("priority"));
        priority->setMaximum(10);

        horizontalLayout_8->addWidget(priority);


        verticalLayout->addLayout(horizontalLayout_8);

        label_4 = new QLabel(TaskWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        description = new QTextEdit(TaskWindow);
        description->setObjectName(QString::fromUtf8("description"));

        verticalLayout->addWidget(description);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(TaskWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_7->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(TaskWindow);

        QMetaObject::connectSlotsByName(TaskWindow);
    } // setupUi

    void retranslateUi(QWidget *TaskWindow)
    {
        TaskWindow->setWindowTitle(QApplication::translate("TaskWindow", "Todo Task Manager ", nullptr));
        label->setText(QApplication::translate("TaskWindow", "Task Input", nullptr));
        label_3->setText(QApplication::translate("TaskWindow", "Task Name ", nullptr));
        label_5->setText(QApplication::translate("TaskWindow", "Urgent (0 = not urgent)", nullptr));
        label_4->setText(QApplication::translate("TaskWindow", "Description", nullptr));
        pushButton->setText(QApplication::translate("TaskWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskWindow: public Ui_TaskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWINDOW_H
