#include "heap.h"
#include <QTableView>
#include <string>
#include <QSqlTableModel>
#include <QObject>
#include <QModelIndex>
#include <QVariant>
#include <QSqlRecord>

heap::heap(QTableView *tableview)
{
    this->tableView=tableview;
    model=new QSqlTableModel;

    model->setTable("Memory");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Address"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Data"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("References"));
    tableview->setModel(model);
}



void heap::addVSptr(string id, string address, string type, string data){
    int row= model->rowCount();

    QVariant Qid = QString::fromStdString(id);
    QVariant Qaddress = QString::fromStdString(address);
    QVariant Qtype = QString::fromStdString(type);
    QVariant Qdata = QString::fromStdString(data);

    model->insertRows(row, 1);
    model->setData(model->index(row, 0), Qid);
    model->setData(model->index(row, 1), Qaddress);
    model->setData(model->index(row, 2), Qtype);
    model->setData(model->index(row, 3), Qdata);
    model->setData(model->index(row, 4), 0);
    model->submitAll();
}

void heap::deleteVSptr(string id){
    model->setFilter( QString::fromStdString("id = "+id));
    model->removeRow(0);
}

void heap::addRef(string id){
    model->setFilter(QString::fromStdString("id = "+id));
    model->setData(model->index(0, 4), model->record(0).value("References").toInt()+1);
    model->setFilter("");
}

void heap::deleteRef(string id){

    model->setFilter(QString::fromStdString("id = "+id));
    model->setData(model->index(0, 4), model->record(0).value("References").toInt()-1);
    model->setFilter("");
}


