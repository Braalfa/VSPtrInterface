#include "heap.h"
#include <QTableView>
#include <string>
#include <QSqlTableModel>
#include <QObject>
#include <QModelIndex>
#include <QVariant>
#include <QSqlRecord>
#include <QSqlQuery>
heap::heap(QTableWidget *tableWidget)
{
}


void heap::addVSptr(string id, string address, string type, string data){
    QTableWidgetItem *idItem = new QTableWidgetItem(id);
    QTableWidgetItem *addressItem = new QTableWidgetItem(address);
    QTableWidgetItem *typeItem = new QTableWidgetItem(type);
    QTableWidgetItem *dataItem = new QTableWidgetItem(data);

    int row=tableWidget->rowCount();

    tableWidget->setItem(row,0,idItem);
    tableWidget->setItem(row,1,addressItem);
    tableWidget->setItem(row,2,typeItem);
    tableWidget->setItem(row,3,dataItem);
    tableWidget->setItem(row,4,new QTableWidgetItem("0"));

}

void heap::deleteVSptr(string id){

    tableWidget->removeRow(this->findRow(id));
}

void heap::addRef(string id){
    int row=this->findRow(id);
    tableWidget->setItem(row,4,new QTableWidgetItem(tableWidget->item(i,0)->text().toInt()+1));
}

void heap::deleteRef(string id){
    int row=this->findRow(id);
    tableWidget->setItem(row,4,new QTableWidgetItem(tableWidget->item(i,0)->text().toInt()-1));
}

int heap::findRow(string id){
    QString text;
    int row=-1;
    for(int i=0;i<tableWidget->rowCount();i++){
        text=tableWidget->item(i,0)->text();
        if(text=QString::fromStdString(id)){
            row= i;
        }
    }
    return row;
}
