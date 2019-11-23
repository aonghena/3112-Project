//
// Created by Alex Onghena on 11/23/19.
//

#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>

LoginWindow::LoginWindow(QWidget *parent):
        QWidget(parent),
        ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));

}

void LoginWindow::onButtonClick() {
    MainWindow *wdg = new MainWindow;
    wdg->show();
    hide();
};

LoginWindow::~LoginWindow()
{
    delete ui;
}
