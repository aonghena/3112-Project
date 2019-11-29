
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
//    QString qstr = QString::fromStdString("sdsd)");
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
    ui->descListView->setModel(descModel);
//    ui->listView->setModel(model);

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButtonClick()));
    QObject::connect(ui->checkBox, SIGNAL(clicked()), this, SLOT(onTodoToggle()));

}

void MainWindow::onTodoToggle(){

//    model = new QStringListModel(this);
//    QStringList List;
//    if (ui->checkBox->isChecked()){
//        List << "Go Food " << "Walk dasdasdasdthe " << "Sign Something";
//    }else{
//        List << "Go Food " << "Walk the " << "Sign Something";
//    }
//    // Make data
//
//    // Populate our model
//    model->setStringList(List);
//
//    ui->listView->setModel(model);
//
//    qDebug () << "Button clicked";
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

