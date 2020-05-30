#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->client= *(new Client());

    ui->setupUi(this);
    runBtn=ui->runBtn;
    serverSettingsBtn=ui->serverSettingsBtn;
    localBtn=ui->localBtn;
    serverBtn=ui->serverBtn;
    tableview=ui->tableView;

    connect(runBtn, SIGNAL (clicked()),this, SLOT (onRunBtn()));
    connect(serverSettingsBtn, SIGNAL (clicked()),this, SLOT (onSettingsServer()));
    connect(localBtn, SIGNAL (clicked()),this, SLOT (onLocalBtn()));
    connect(serverBtn, SIGNAL (clicked()),this, SLOT (onServerBtn()));

    localBtn->setChecked(true);
    serverBtn->setChecked(false);


}

void MainWindow::onRunBtn()
{

}

void MainWindow::onLocalBtn()
{
    localBtn->setChecked(true);
    serverBtn->setChecked(false);

}

void MainWindow::onServerBtn()
{
    localBtn->setChecked(false);
    serverBtn->setChecked(true);

}

void MainWindow::onSettingsServer()
{
    Dialog *d = new Dialog(this, client);
    d->open();
}

MainWindow::~MainWindow()
{
    delete ui;
}
