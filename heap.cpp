#include "heap.h"
#include <QTableView>
#include <string>
#include <QSqlTableModel>
#include <QObject>
#include <QModelIndex>
#include <QVariant>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QStringList>

Heap::Heap(QTableWidget *tableWidget)
{
    this->tableWidget=tableWidget;
    QStringList headers= *new QStringList;
    headers.append("Id");
    headers.append("Address");
    headers.append("Type");
    headers.append("Data");
    headers.append("References");

    tableWidget->setHorizontalHeaderLabels(headers);
}


void Heap::addVSptr(string id, string address, string type, string data){

    QTableWidgetItem *idItem = new QTableWidgetItem(QString::fromStdString(id));
    QTableWidgetItem *addressItem = new QTableWidgetItem(QString::fromStdString(address));
    QTableWidgetItem *typeItem = new QTableWidgetItem(QString::fromStdString(type));
    QTableWidgetItem *dataItem = new QTableWidgetItem(QString::fromStdString(data));


    int row=tableWidget->rowCount();
    tableWidget->setRowCount(row+1);
    tableWidget->setItem(row,0,idItem);
    tableWidget->setItem(row,1,addressItem);
    tableWidget->setItem(row,2,typeItem);
    tableWidget->setItem(row,3,dataItem);
    tableWidget->setItem(row,4,new QTableWidgetItem("0"));

}

void Heap::deleteVSptr(string id){

    tableWidget->removeRow(this->findRow(id));
}

void Heap::addRef(string id){
    int row=this->findRow(id);
    tableWidget->setItem(row,4,new QTableWidgetItem(tableWidget->item(row,0)->text().toInt()+1));
}

void Heap::deleteRef(string id){
    int row=this->findRow(id);
    tableWidget->setItem(row,4,new QTableWidgetItem(tableWidget->item(row,0)->text().toInt()-1));
}

int Heap::findRow(string id){
    QString text;
    int row=-1;
    for(int i=0;i<tableWidget->rowCount();i++){
        text=tableWidget->item(i,0)->text();
        if(text==QString::fromStdString(id)){
            row= i;
        }
    }
    return row;
}
