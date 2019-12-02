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

/**
 * LoginWindow
 * Constructor for the login window
 * @param parent - parent window
 */
LoginWindow::LoginWindow(QWidget *parent):
        QWidget(parent),
        ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onSignButtonClick()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onRegButtonClick()));

}
/**
 * onSignButtonClick()
 * sign in button re-direct
 */
void LoginWindow::onSignButtonClick() {
    bool pass = false;

    std::string email = ui->emailInput->text().toStdString();
    std::string password = ui->passwordInput->text().toStdString();

    Database *db = MainWindow::database.get();
    User *user = User::getByEmailAndPassword(db, email, password);

    if(user != nullptr){
        pass = true;
        MainWindow::currentUser = shared_ptr<User> (user);
    }else{
        QMessageBox::information(
                this,
                tr("TODO"),
                tr("Invalid email or password.") );
    }

    if(pass && MainWindow::currentUser != nullptr){
        MainWindow *wdg = new MainWindow();
        wdg->show();
        hide();
    }

};

/**
 * onregButtonClick()
 * re-directs to register window
 */
void LoginWindow::onRegButtonClick() {
    RegisterWindow *wdg = new RegisterWindow;
    wdg->show();
    hide();
};

/**
 * LoginWindow
 * de-constructor
 */
LoginWindow::~LoginWindow()
{
    delete ui;
}
