//
// Created by Alex Onghena on 11/18/19.
//

#include "mainwindow.h"
#include "taskwindow.h"
#include "ui_taskwindow.h"
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>

TaskWindow::TaskWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::TaskWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));

}

void TaskWindow::onButtonClick() {
    MainWindow *wdg = new MainWindow;
    wdg->show();
    hide();
    qDebug () << "Button clicked";
};


TaskWindow::~TaskWindow()
{
    delete ui;
}
