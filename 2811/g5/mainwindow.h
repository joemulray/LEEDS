/****************************************************************************
** Form interface generated from reading ui file 'mainwindow.ui'
**
** Created by User Interface Compiler
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();






private slots:
    void on_loginButton_pressed();
    void on_learnButton_pressed();
    void on_minervaButton_2_pressed();
    void on_logout_pressed();
    void on_logout_2_pressed();

    void on_minervaButton_3_pressed();

    void on_pushButton_22_pressed();

    void on_logout_3_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_pressed();

    void on_pushButton_15_pressed();

    void on_minervaButton_4_pressed();

    void on_logout_4_pressed();

    void on_pushButton_30_pressed();

    void on_pushButton_25_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
