//
// Created by Alex Onghena on 11/23/19.
//

#ifndef TODOS_LOGINWINDOW_H
#define TODOS_LOGINWINDOW_H


#include <QMainWindow>
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>

namespace Ui {
    class LoginWindow;
}

class LoginWindow : public QWidget
{
Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

public slots:
    void onSignButtonClick();
    void onRegButtonClick();

private:
    Ui::LoginWindow *ui;
};

#endif //TODOS_LOGINWINDOW_H
