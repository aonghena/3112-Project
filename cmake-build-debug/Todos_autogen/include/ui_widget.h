/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelProgramName;
    QLabel *labelVersion;
    QLabel *labelAuthor;
    QLabel *labelEmail;
    QPushButton *pushButtonBack;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(415, 203);
        verticalLayout = new QVBoxLayout(About);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelProgramName = new QLabel(About);
        labelProgramName->setObjectName(QString::fromUtf8("labelProgramName"));

        verticalLayout->addWidget(labelProgramName);

        labelVersion = new QLabel(About);
        labelVersion->setObjectName(QString::fromUtf8("labelVersion"));

        verticalLayout->addWidget(labelVersion);

        labelAuthor = new QLabel(About);
        labelAuthor->setObjectName(QString::fromUtf8("labelAuthor"));

        verticalLayout->addWidget(labelAuthor);

        labelEmail = new QLabel(About);
        labelEmail->setObjectName(QString::fromUtf8("labelEmail"));

        verticalLayout->addWidget(labelEmail);

        pushButtonBack = new QPushButton(About);
        pushButtonBack->setObjectName(QString::fromUtf8("pushButtonBack"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonBack->sizePolicy().hasHeightForWidth());
        pushButtonBack->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButtonBack);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "GitUI About", nullptr));
        labelProgramName->setText(QApplication::translate("About", "programName", nullptr));
        labelVersion->setText(QApplication::translate("About", "version", nullptr));
        labelAuthor->setText(QApplication::translate("About", "Author", nullptr));
        labelEmail->setText(QApplication::translate("About", "e-mail", nullptr));
        pushButtonBack->setText(QApplication::translate("About", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
