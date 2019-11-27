//
// Created by Alex Onghena on 11/24/19.
//

#ifndef TODOS_REGISTERWINDOW_H
#define TODOS_REGISTERWINDOW_H
#include <QMainWindow>
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QInputDialog>

namespace Ui {
    class RegisterWindow;
}

class RegisterWindow : public QWidget
{
Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();

public slots:
    void onLoginButtonClick();
    void onRegButtonClick();

private:
    Ui::RegisterWindow *ui;
};



#endif //TODOS_REGISTERWINDOW_H
