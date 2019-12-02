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

/**
 * Main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}