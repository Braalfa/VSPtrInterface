#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QTableWidget>
#include <client.h>
#include "dialog.h"
#include "heap.h"
#include <thread>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void hiloTableVi();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *serverSettingsBtn;
    QRadioButton *localBtn;
    QRadioButton *serverBtn;
    QTableWidget *tableview;
    QPushButton *run;
    Dialog *dialog;
    Client client;
    Ui::MainWindow *ui;

private slots:

    void updateTableView();
    void onLocalBtn();
    void onServerBtn();
    void runT();
    void onSettingsServer();
};

#endif // MAINWINDOW_H
