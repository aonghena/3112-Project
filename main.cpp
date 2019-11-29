#include <iostream>

#include "User.h"
#include "Task.h"
#include "UrgentTask.h"
#include "Database.h"
#include <QApplication>
#include <QDebug>

using namespace std;

#include <QApplication>
#include <QPushButton>
#include "UI/mainwindow.h"
#include "UI/taskwindow.h"
#include "UI/loginwindow.h"
#include "User.h"
#include <ctime>


//For setting up QT with CLion check https://stackoverflow.com/questions/30235175/how-to-configure-clion-ide-for-qt-framework

int main(int argc, char *argv[])
{
//    Database *db = MainWindow::database.get();
//    vector<Task*> tasks = Task::getTasks(db);
//
//    User *user = new User("dawson", "dheide@uncc.edu", "password123");
//    user->save(db);

//    Task *task1 = new Task("Garbage", "Take out trash", 1);
//    cout << task1->getCreatedAt() << endl;
//    task1->save(db);
//    cout << task1->getCreatedAt() << endl;
//
//    Task *task2 = new Task("Homework", "Finish homework", 1);
//    task2->save(db);

//    for(auto & x : tasks) {
//        cout << x->getTitle() << " " << x->getDescription() << endl;
//    }
//
//    time_t t ;
//    struct tm *tmp ;
//    char MY_TIME[50];
//    time( &t );
//    tmp = localtime( &t );
//    strftime(MY_TIME, sizeof(MY_TIME), "%x - %I:%M%p", tmp);
//    cout << MY_TIME << endl;

//    cout << User::getByEmail(MainWindow::database.get(), "dheide@uncc.edu")->getTasks(MainWindow::database.get())[0]->getCreatedAt() << endl;

//    return 0;
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}