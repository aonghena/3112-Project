//
// Created by Alex Onghena on 11/18/19.
//

#ifndef TODOS_TASKWINDOW_H
#define TODOS_TASKWINDOW_H


#include <QMainWindow>
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>
#include <QMessageBox>
namespace Ui {
    class TaskWindow;
}

class TaskWindow : public QWidget
{
Q_OBJECT

public:
    explicit TaskWindow(QWidget *parent = 0);
    ~TaskWindow();

public slots:
    void onButtonClick();

private:
    Ui::TaskWindow *ui;
};



#endif //TODOS_TASKWINDOW_H
