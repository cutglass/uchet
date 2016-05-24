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

    void writeSettings();
    void loadSettings();

private:
    Ui::MainWindow *ui;
    QSettings *settings;
};

#endif // MAINWINDOW_H
