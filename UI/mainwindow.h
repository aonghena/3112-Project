
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>
#include "Database.h"
#include "User.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:

    static shared_ptr<Database> database;
    static shared_ptr<User> currentUser;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onButtonClick();
    void onTodoToggle();

private:
    Ui::MainWindow *ui;
    QStringListModel *titleModel;
    QStringListModel *descModel;

};

#endif // MAINWINDOW_H