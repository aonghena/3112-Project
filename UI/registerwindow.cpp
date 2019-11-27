//
// Created by Alex Onghena on 11/24/19.
//

#include "registerwindow.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_registerwindow.h"
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent):
        QWidget(parent),
        ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onRegButtonClick()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onLoginButtonClick()));

}

void RegisterWindow::onLoginButtonClick() {
    LoginWindow *wdg = new LoginWindow;
    wdg->show();
    hide();
};

void RegisterWindow::onRegButtonClick() {
    bool pass = false;

    std::string email = ui->usernameInput->text().toStdString();
    std::string password = ui->passwordInput->text().toStdString();
    std::string name = ui->nameInput->text().toStdString();

    if(!(email == "" || password == "" || name == "")){
         pass = true;
    }else{
        QMessageBox::information(
                this,
                tr("TODO"),
                tr("Invalid INFO.") );
    }


    if(pass){

        //add to the database here

        MainWindow *wdg = new MainWindow;
        wdg->show();
        hide();
    }

};


RegisterWindow::~RegisterWindow()
{
    delete ui;
}
