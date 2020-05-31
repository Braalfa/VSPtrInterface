#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "heap.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->client= *(new Client());
    dialog = new Dialog(this, client);

    ui->setupUi(this);
    runBtn=ui->runBtn;
    serverSettingsBtn=ui->serverSettingsBtn;
    localBtn=ui->localBtn;
    serverBtn=ui->serverBtn;
    tableview=ui->tableWidget;

    tableview->setRowCount(0);
    tableview->setColumnCount(5);

    connect(runBtn, SIGNAL (clicked()),this, SLOT (onRunBtn()));
    connect(serverSettingsBtn, SIGNAL (clicked()),this, SLOT (onSettingsServer()));
    connect(localBtn, SIGNAL (clicked()),this, SLOT (onLocalBtn()));
    connect(serverBtn, SIGNAL (clicked()),this, SLOT (onServerBtn()));

    localBtn->setChecked(true);
    serverBtn->setChecked(false);
    this->heap=new Heap(tableview);

}

void MainWindow::onRunBtn()
{
    localBtn->setEnabled(false);
    serverBtn->setEnabled(false);
    if(!localBtn->isChecked()){
        int result =client.logIn();
        QMessageBox message;
        if(result=-1){
            message.setIcon(QMessageBox::Warning);
            message.setText("Connection Failed");
            message.exec();
        }
    }

    heap->addVSptr("1","eet","3","4");
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
    dialog->open();
}

MainWindow::~MainWindow()
{
    delete ui;
}
