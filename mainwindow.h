#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QTableWidget>
#include "client.h"
#include "dialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *runBtn;
    QPushButton *serverSettingsBtn;
    QRadioButton *localBtn;
    QRadioButton *serverBtn;
    QTableWidget *tableview;
    Dialog *dialog;
    Client client;
    Ui::MainWindow *ui;
private slots:
    void onRunBtn();
    void onLocalBtn();
    void onServerBtn();
    void onSettingsServer();
};

#endif // MAINWINDOW_H
