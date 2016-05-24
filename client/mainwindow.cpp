#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setu
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::writeSettings()
{
    QSettings settings("client.conf",QSettings::IniFormat);
}

MainWindow::loadSettings()
{

}
