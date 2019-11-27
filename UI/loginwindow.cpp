//
// Created by Alex Onghena on 11/23/19.
//

#include "loginwindow.h"
#include "mainwindow.h"
#include "registerwindow.h"
#include "ui_loginwindow.h"
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent):
        QWidget(parent),
        ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onSignButtonClick()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onRegButtonClick()));

}

void LoginWindow::onSignButtonClick() {
    bool pass = false;

    std::string email = ui->emailInput->text().toStdString();
    std::string password = ui->passwordInput->text().toStdString();

    if(!(email == "" || password == "")){
        pass = true;
    }else{
        QMessageBox::information(
                this,
                tr("TODO"),
                tr("Invalid INFO.") );
    }
    ///
    ///Database verification here
    ///

    if(pass){
        MainWindow *wdg = new MainWindow;
        wdg->show();
        hide();
    }

};

void LoginWindow::onRegButtonClick() {
    RegisterWindow *wdg = new RegisterWindow;
    wdg->show();
    hide();

};


LoginWindow::~LoginWindow()
{
    delete ui;
}
