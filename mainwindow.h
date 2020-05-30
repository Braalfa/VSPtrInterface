#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QTableView>
#include "client.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPushButton *runBtn;
    QPushButton *serverSettingsBtn;
    QRadioButton *localBtn;
    QRadioButton *serverBtn;
    QTableView *tableview;
    Client client;

private:
    Ui::MainWindow *ui;
private slots:
    void onRunBtn();
    void onLocalBtn();
    void onServerBtn();
    void onSettingsServer();
};

#endif // MAINWINDOW_H
