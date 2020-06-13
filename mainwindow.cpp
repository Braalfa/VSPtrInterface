#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <thread>
#include "TList.h"
#include "TNode.h"
#include <chrono>
#include <QApplication>
#include <VSPtr.cpp>

GarbageType GarbageCollector::type;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->client= *(new Client());
    dialog = new Dialog(this, &client);

    ui->setupUi(this);

    serverSettingsBtn=ui->serverSettingsBtn;
    localBtn=ui->localBtn;
    serverBtn=ui->serverBtn;
    tableview=ui->tableWidget;
    run = ui->runBtn;

    tableview->setRowCount(0);
    tableview->setColumnCount(5);

    QStringList headers= *new QStringList;
    headers.append("Id");
    headers.append("Address");
    headers.append("Type");
    headers.append("Data");
    headers.append("References");

    tableview->setHorizontalHeaderLabels(headers);



    connect(serverSettingsBtn, SIGNAL (clicked()),this, SLOT (onSettingsServer()));
    connect(localBtn, SIGNAL (clicked()),this, SLOT (onLocalBtn()));
    connect(serverBtn, SIGNAL (clicked()),this, SLOT (onServerBtn()));
    connect(run, SIGNAL (clicked()),this, SLOT (runT()));

    localBtn->setChecked(true);
    serverBtn->setChecked(false);
    GarbageCollector::setType(Local);
    std::thread first(&MainWindow::hiloTableVi, this);
    first.detach();
}

void MainWindow::hiloTableVi()
{
    while (true) {
        this_thread::sleep_for (chrono::milliseconds(300));
        updateTableView();
    }
}

void MainWindow::runT(){
    VSPtr<int> v=VSPtr<int>::New();
    v=7;
    VSPtr<int> j=VSPtr<int>::New();
    j=8;
    VSPtr<int> m=VSPtr<int>::New();
    m=9;
    v=j;
    m=v;
    v=10;
}

void MainWindow::onLocalBtn()
{
    localBtn->setChecked(true);
    serverBtn->setChecked(false);
    GarbageCollector::setType(Local);

}

void MainWindow::onServerBtn()
{
    localBtn->setChecked(false);
    serverBtn->setChecked(true);
    GarbageCollector::setType(Remote);
}

void MainWindow::onSettingsServer()
{
    dialog->open();
    if(dialog->connectionSucces){
        onServerBtn();
    }else{
        onLocalBtn();
    }
}



void MainWindow::updateTableView(){
    Heap heap = * Heap::getInstance();
    int length =heap.idList.largo;
    tableview->setRowCount(length);
    for(int i =0; i<heap.idList.largo; i++){
        tableview->setItem( i, 0, new QTableWidgetItem(QString::fromStdString(heap.idList.getNodoPos(i)->getValue())));
        tableview->setItem( i, 1, new QTableWidgetItem(QString::fromStdString(heap.addreesList.getNodoPos(i)->getValue())));
        tableview->setItem( i, 2, new QTableWidgetItem(QString::fromStdString(heap.typeList.getNodoPos(i)->getValue())));
        tableview->setItem( i, 3, new QTableWidgetItem(QString::fromStdString(heap.dataList.getNodoPos(i)->getValue())));
        tableview->setItem( i, 4, new QTableWidgetItem(QString::fromStdString(heap.referencesList.getNodoPos(i)->getValue())));
    }
}






MainWindow::~MainWindow()
{
    delete ui;
}
