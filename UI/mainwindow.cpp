
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
    vector<UrgentTask *> Utasks = MainWindow::currentUser->getUTasks(MainWindow::database.get());

    for(int x = 0; x < Utasks.size(); x++) {
        if(Utasks[x]->isCompleted() == 0){
            titleList += Utasks[x]->getTitle().c_str();
        }
    }
    cout << Utasks.size() << endl;
    for(int x = 0; x < tasks.size(); x++) {
        if(tasks[x]->isCompleted() == 0){
            titleList += tasks[x]->getTitle().c_str();
        }
    }

    // Populate our model
    if(!(titleList.empty())) {
        titleModel->setStringList(titleList);
    }

    string tempDesc = "";
    if(Utasks.size() != 0) {
        tempDesc = Utasks[0]->getDescription()+"\n\nUrgency:" + std::to_string(Utasks[0]->getPriority()) +"\nDate Created:"+Utasks[0]->getCreatedAt();
    }else  if(tasks.size() != 0) {
        tempDesc = tasks[0]->getDescription() + "\n\n\n Date Created:" + tasks[0]->getCreatedAt();
    }
    ui->descText->setText(tempDesc.c_str());

    ui->titleListView->setModel(titleModel);
};


void MainWindow::completeTask(){
    vector<Task *> tasks = MainWindow::currentUser->getTasks(MainWindow::database.get());
    vector<UrgentTask *> Utasks = MainWindow::currentUser->getUTasks(MainWindow::database.get());
    int x = ui->titleListView->selectionModel()->currentIndex().row();
    int m = Utasks.size();
    cout << x << endl;
    cout << m << endl;
    if(x != -1) {
        if(x <= m-1){
            database->deleteTask(Utasks[x]->getId());
        }else{
            database->deleteTask(tasks[x-m]->getId());
        }
        refreshList();
    }
    connect(ui->titleListView->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this, SLOT(handleSelectionChanged(QItemSelection)));
}


void MainWindow::handleSelectionChanged(const QItemSelection& selection)
{
    vector<Task *> tasks = MainWindow::currentUser->getTasks(MainWindow::database.get());
    vector<UrgentTask *> Utasks = MainWindow::currentUser->getUTasks(MainWindow::database.get());
    int m = Utasks.size();
    int x = selection.indexes().value(0).row();
    cout << m << endl;
    cout << x << endl;
    string tempDesc = "";
    //decides if an urgent task was clicked or not
    if(x <= m-1){
        tempDesc = Utasks[x]->getDescription()+"\n\nUrgency:" + std::to_string(Utasks[x]->getPriority()) +"\nDate Created:"+Utasks[x]->getCreatedAt();
    }else{
        tempDesc = tasks[x-m]->getDescription()+"\n\n\nDate Created:"+tasks[x-m]->getCreatedAt();
    }

    ui->descText->setText(tempDesc.c_str());

}


void MainWindow::onButtonClick() {
    TaskWindow *wdg = new TaskWindow;
    wdg->show();
    hide();
};

MainWindow::~MainWindow()
{
    delete ui;
}

