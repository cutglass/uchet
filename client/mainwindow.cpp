#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings=new QSettings("client.conf",QSettings::IniFormat);
    loadSettings();
    createConnection();
}

MainWindow::~MainWindow()
{
    writeSettings();
    delete ui;
    delete settings;
}

void MainWindow::loadSettings()
{
    db_host=settings->value("db_host","127.0.0.1").toString();
    db_name=settings->value("db_name","db_uchet").toString();
    db_user=settings->value("db_user","postgres").toString();
    db_pass=settings->value("db_pass","22").toString();
}


void MainWindow::writeSettings()
{
    settings->setValue("db_host",db_host);
    settings->setValue("db_name",db_name);
    settings->setValue("db_user",db_user);
    settings->setValue("db_pass",db_pass);
}

bool MainWindow::createConnection()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_user);
    db.setPassword(db_pass);
    if(!db.open()){
        QSqlError sqlerror;
                sqlerror=db.lastError();
        QMessageBox::critical(this,"ALARM!",sqlerror.text());
        return false;
    };
    return true;
}
