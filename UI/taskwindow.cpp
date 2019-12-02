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

/**
 * Task Window
 * task window constructor
 * @param parent - parent widget
 */
TaskWindow::TaskWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::TaskWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));
}

/**
 * onButtonClick()
 * adds created task to database and re-direct to main window
 */
void TaskWindow::onButtonClick() {

    bool pass = true;
    string title = ui->title->text().toStdString();
    string description = ui->description->toPlainText().toStdString();
    int priority = ui->priority->cleanText().toInt();

    cout << title << description << priority << endl;

    if(title == "" || description == ""){
        pass = false;
        QMessageBox::information(
                this,
                tr("TODO"),
                tr("Invalid title or description") );
    }else if( title.length() > 200 || description.length() > 10000){
        pass = false;
        QMessageBox::information(
                this,
                tr("TODO"),
                tr("Invalid Length.") );
    }

    if(pass) {
        Database *database = MainWindow::database.get();
        MainWindow::currentUser->createTask(database, title, description, priority);
        MainWindow *wdg = new MainWindow();
        wdg->show();
        hide();
    }
};

/**
 * taskWindow
 * de-constructor
 */
TaskWindow::~TaskWindow()
{
    delete ui;
}
