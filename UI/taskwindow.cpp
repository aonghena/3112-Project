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

    string title = ui->title->text().toStdString();
    string description = ui->description->toPlainText().toStdString();
    int priority = ui->priority->cleanText().toInt();

    cout << title << description << priority << endl;

    Database *database = MainWindow::database.get();
//    if(priority > 0) {
//        UrgentTask *task = new UrgentTask(title, description, MainWindow::currentUser->getId(), priority);
//        task->save(database);
//    } else {
//        Task *task = new Task(title, description, MainWindow::currentUser->getId());
//        task->save(database);
//    }
//
    cout << "b4 cal" << endl;
    MainWindow::currentUser->createTask(database, title, description, priority);
    MainWindow *wdg = new MainWindow();
    wdg->show();
    hide();
};


TaskWindow::~TaskWindow()
{
    delete ui;
}
