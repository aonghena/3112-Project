
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

    refreshList();

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));
    QObject::connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(completeTask()));
    connect(ui->titleListView->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(handleSelectionChanged(QItemSelection)));
}

void MainWindow::refreshList(){

    ui->nameLabel->setText(MainWindow::currentUser->getName().c_str());

    titleModel = new QStringListModel(this);
    descModel = new QStringListModel(this);

    // Make data
    QStringList titleList;

    vector<Task *> tasks = MainWindow::currentUser->getTasks(MainWindow::database.get());
//    cout << tasks.size() << endl;
    for(int x = 0; x < tasks.size(); x++) {
        if(tasks[x]->isCompleted() == 0){
            titleList += tasks[x]->getTitle().c_str();
        }
    }
    // Populate our model
    if(!(titleList.empty())) {
        titleModel->setStringList(titleList);
    }
    ui->titleListView->setModel(titleModel);

    if(tasks.size() != 0) {
        string tempDesc = tasks[0]->getDescription()+"\n\n\n Date Created:"+tasks[0]->getCreatedAt();
        ui->descText->setText(tempDesc.c_str());
    }else{
        ui->descText->setText("");
    }
};


void MainWindow::completeTask(){
    vector<Task *> tasks = MainWindow::currentUser->getTasks(MainWindow::database.get());
    int x = ui->titleListView->selectionModel()->currentIndex().row();
    if(x != -1) {
        cout << tasks[x]->getId() << endl;
        database->deleteTask(tasks[x]->getId());
        refreshList();
    }
    connect(ui->titleListView->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(handleSelectionChanged(QItemSelection)));
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

