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

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}