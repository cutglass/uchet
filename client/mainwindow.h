#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void writeSettings();
    void loadSettings();
    bool createConnection();

private:
    Ui::MainWindow *ui;
    QSettings *settings;
    QString db_name;
    QString db_host;
    QString db_user;
    QString db_pass;
    QSqlDatabase db;

};

#endif // MAINWINDOW_H
