#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QTableWidget>
#include <client.h>
#include "dialog.h"
#include "heap.h"

/**
 * Clase principal la cual se encarga de mostrar los botones principlaes y da la opcion de modificar el garbage collector
 * entre local y remoto ademas muestra graficamente como funciona el HEAP
 */
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
