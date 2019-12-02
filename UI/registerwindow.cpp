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

/**
 * RegisterWindow
 * register window constructor
 * @param parent - parent widget
 */
RegisterWindow::RegisterWindow(QWidget *parent):
        QWidget(parent),
        ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onRegButtonClick()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onLoginButtonClick()));

}

/**
 * onLoginButtonClick
 * function to go to login window
 */
void RegisterWindow::onLoginButtonClick() {
    LoginWindow *wdg = new LoginWindow;
    wdg->show();
    hide();
};

/**
 * onRegButtonClick
 * adds the user to the database and dre-direct to main window
 */
void RegisterWindow::onRegButtonClick() {

    bool pass = false;
    User *user = nullptr;

    std::string email = ui->usernameInput->text().toStdString();
    std::string password = ui->passwordInput->text().toStdString();
    std::string name = ui->nameInput->text().toStdString();

    Database *database = MainWindow::database.get();

    if(!(email == "" || password == "" || name == "")
        && (email.length() < 400 || password.length() < 400  || name.length() < 400 )
        && User::getByEmail(database, email) == nullptr){
        pass = true;
        user = new User(name, email, password);
        user->save(database);
        MainWindow::currentUser = shared_ptr<User> (user);
    } else{
        QMessageBox::information(
                this,
                tr("TODO"),
                tr("Invalid INFO.") );
    }

    if(pass && MainWindow::currentUser != nullptr){
        //add to the database here
        MainWindow *wdg = new MainWindow;
        wdg->show();
        hide();
    }

};

/**
 * de-constructor
 */
RegisterWindow::~RegisterWindow()
{
    delete ui;
}
