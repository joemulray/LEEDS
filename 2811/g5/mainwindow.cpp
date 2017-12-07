#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_loginButton_pressed()
{
    QObject::connect(ui->loginButton, SIGNAL(clicked()), ui->login, SLOT(hide()));
    QObject::connect(ui->loginButton, SIGNAL(clicked()), ui->homepage, SLOT(show()));
}

void MainWindow::on_learnButton_pressed()
{
    QObject::connect(ui->learnButton, SIGNAL(clicked()), ui->homepage, SLOT(hide()));
    QObject::connect(ui->learnButton, SIGNAL(clicked()), ui->learnpage, SLOT(show()));
}

void MainWindow::on_minervaButton_2_pressed()
{
    QObject::connect(ui->minervaButton_2, SIGNAL(clicked()), ui->learnpage, SLOT(hide()));
    QObject::connect(ui->minervaButton_2, SIGNAL(clicked()), ui->homepage, SLOT(show()));
}

void MainWindow::on_logout_pressed()
{
    QObject::connect(ui->logout, SIGNAL(clicked()), ui->homepage, SLOT(hide()));
    QObject::connect(ui->logout, SIGNAL(clicked()), ui->login, SLOT(show()));
}

void MainWindow::on_logout_2_pressed()
{
    QObject::connect(ui->logout_2, SIGNAL(clicked()), ui->learnpage, SLOT(hide()));
    QObject::connect(ui->logout_2, SIGNAL(clicked()), ui->login, SLOT(show()));
}

void MainWindow::on_minervaButton_3_pressed()
{
    QObject::connect(ui->minervaButton_3, SIGNAL(clicked()), ui->studentservicespage, SLOT(hide()));
    QObject::connect(ui->minervaButton_3, SIGNAL(clicked()), ui->homepage, SLOT(show()));
}

void MainWindow::on_pushButton_22_pressed()
{
    QObject::connect(ui->pushButton_22, SIGNAL(clicked()), ui->studentservicespage, SLOT(hide()));
    QObject::connect(ui->pushButton_22, SIGNAL(clicked()), ui->learnpage, SLOT(show()));
}

void MainWindow::on_logout_3_pressed()
{
    QObject::connect(ui->logout_3, SIGNAL(clicked()), ui->studentservicespage, SLOT(hide()));
    QObject::connect(ui->logout_3, SIGNAL(clicked()), ui->login, SLOT(show()));
}

void MainWindow::on_pushButton_7_pressed()
{
    QObject::connect(ui->pushButton_7, SIGNAL(clicked()), ui->homepage, SLOT(hide()));
    QObject::connect(ui->pushButton_7, SIGNAL(clicked()), ui->studentservicespage, SLOT(show()));
}

void MainWindow::on_pushButton_3_pressed()
{
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), ui->learnpage, SLOT(hide()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), ui->studentservicespage, SLOT(show()));
}

void MainWindow::on_pushButton_6_pressed()
{
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), ui->homepage, SLOT(hide()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), ui->librarypage, SLOT(show()));
}

void MainWindow::on_pushButton_pressed()
{
    QObject::connect(ui->pushButton, SIGNAL(clicked()), ui->learnpage, SLOT(hide()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), ui->librarypage, SLOT(show()));
}

void MainWindow::on_pushButton_15_pressed()
{
    QObject::connect(ui->pushButton_15, SIGNAL(clicked()), ui->studentservicespage, SLOT(hide()));
    QObject::connect(ui->pushButton_15, SIGNAL(clicked()), ui->librarypage, SLOT(show()));
}

void MainWindow::on_minervaButton_4_pressed()
{
    QObject::connect(ui->minervaButton_4, SIGNAL(clicked()), ui->librarypage, SLOT(hide()));
    QObject::connect(ui->minervaButton_4, SIGNAL(clicked()), ui->homepage, SLOT(show()));
}

void MainWindow::on_logout_4_pressed()
{
    QObject::connect(ui->logout_4, SIGNAL(clicked()), ui->librarypage, SLOT(hide()));
    QObject::connect(ui->logout_4, SIGNAL(clicked()), ui->login, SLOT(show()));
}

void MainWindow::on_pushButton_30_pressed()
{
    QObject::connect(ui->pushButton_30, SIGNAL(clicked()), ui->librarypage, SLOT(hide()));
    QObject::connect(ui->pushButton_30, SIGNAL(clicked()), ui->learnpage, SLOT(show()));
}

void MainWindow::on_pushButton_25_pressed()
{
    QObject::connect(ui->pushButton_25, SIGNAL(clicked()), ui->librarypage, SLOT(hide()));
    QObject::connect(ui->pushButton_25, SIGNAL(clicked()), ui->studentservicespage, SLOT(show()));
}
