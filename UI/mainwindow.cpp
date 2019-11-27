
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>
#include "taskwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    QString qstr = QString::fromStdString("sdsd)");
    ui->setupUi(this);
    model = new QStringListModel(this);

    // Make data
    QStringList List;
    List << "Go Food Shopping" << "Walk the Dog" << "Sign Something";

    // Populate our model
    model->setStringList(List);

    ui->listView->setModel(model);
    ui->listView->setModel(model);

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));
    QObject::connect(ui->checkBox, SIGNAL(clicked()), this, SLOT(onTodoToggle()));

}

void MainWindow::onTodoToggle(){
    model = new QStringListModel(this);
    QStringList List;
    if (ui->checkBox->isChecked()){
        List << "Go Food " << "Walk dasdasdasdthe " << "Sign Something";
    }else{
        List << "Go Food " << "Walk the " << "Sign Something";
    }
    // Make data



    // Populate our model
    model->setStringList(List);

    ui->listView->setModel(model);

    qDebug () << "Button clicked";
}

void MainWindow::onButtonClick() {
    TaskWindow *wdg = new TaskWindow;
    wdg->show();
    hide();
    qDebug () << "Button clicked";

};

MainWindow::~MainWindow()
{
    delete ui;
}

