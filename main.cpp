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

//For setting up QT with CLion check https://stackoverflow.com/questions/30235175/how-to-configure-clion-ide-for-qt-framework

int main(int argc, char *argv[])
{

    Database *db = new Database();

//    User *user1 = new User("Dawson", "dheide@uncc.edu", "password123");
//    user1->save(db);
//
//    User *user2 = new User("Hailey", "hbrown@uncc.edu", "hotdog");
//    user2->save(db);
//
//    User *user3 = new User("Anna", "anna@uncc.edu", "jdog123");
//    user3->save(db);

//    vector<User*> users = User::getUsers(db);
//
//    for(int x = 0; x < users.size(); x++) {
//        cout << users[x]->getName() << endl;
//    }

//    UrgentTask *task = new UrgentTask("College Application", "Apply for college", 2, 1);
//    task->save(db);

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//
//    return a.exec();
    return 0;
}