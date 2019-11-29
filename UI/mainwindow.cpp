
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>
#include "taskwindow.h"

shared_ptr<Database> MainWindow::database (new Database());
shared_ptr<User> MainWindow::currentUser (nullptr);

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->nameLabel->setText(MainWindow::currentUser->getName().c_str());

    titleModel = new QStringListModel(this);
    descModel = new QStringListModel(this);

    // Make data
    QStringList titleList;
    QStringList descList;

    vector<Task *> tasks = MainWindow::currentUser->getTasks(MainWindow::database.get());
//    cout << tasks.size() << endl;
    for(int x = 0; x < tasks.size(); x++) {
        titleList += tasks[x]->getTitle().c_str();
        descList += tasks[x]->getDescription().c_str();
    }

    // Populate our model
    if(!(titleList.empty() || descList.empty())) {
        titleModel->setStringList(titleList);
        descModel->setStringList(descList);
    }

    ui->titleListView->setModel(titleModel);


    if(tasks.size() != 0) {
        string tempDesc = tasks[0]->getDescription()+"\n\n\n Date Created:"+tasks[0]->getCreatedAt();
        ui->descText->setText(tempDesc.c_str());
    }
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));
    QObject::connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(deleteTask()));
    connect(ui->titleListView->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(handleSelectionChanged(QItemSelection)));
}

void MainWindow::deleteTask(){
    //todo remove or create task

}


void MainWindow::handleSelectionChanged(const QItemSelection& selection)
{
    vector<Task *> tasks = MainWindow::currentUser->getTasks(MainWindow::database.get());
    int x = selection.indexes().value(0).row();
    string tempDesc = tasks[x]->getDescription()+"\n\n\n Date Created:"+tasks[x]->getCreatedAt();
    ui->descText->setText(tempDesc.c_str());

}


void MainWindow::onButtonClick() {
    TaskWindow *wdg = new TaskWindow;
    wdg->show();
    hide();
//    qDebug () << "Button clicked";

};

MainWindow::~MainWindow()
{
    delete ui;
}

