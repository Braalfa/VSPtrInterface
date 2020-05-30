#ifndef HEAP_H
#define HEAP_H
#include <QTableView>
#include <string>
#include <QSqlTableModel>
#include <QObject>

using namespace std;

class heap
{

private:
    QTableView *tableView;
    QSqlTableModel *model;

public:
    heap(QTableView *tableview);
    void addVSptr(string id, string address, string type, string data);
    void deleteVSptr(string id);
    void addRef(string id);
    void deleteRef(string id);
};

#endif // HEAP_H
