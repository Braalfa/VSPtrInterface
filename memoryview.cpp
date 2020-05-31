#include "memoryview.h"

#include <QLabel>
#include "memoryview.h"

MemoryView::MemoryView(QWidget *parent) :
       QTableView(parent)
{}

void MemoryView::rowsInserted(const QModelIndex &parent, int start, int end) {
       QTableView::rowsInserted(parent, start, end);
       for (int row = start; row <= end; ++row) {
           insertHorizontal(row);
       }
}

void MemoryView::insertHorizontal(int row) {
       for (int i = 0; i < 5; ++i) {
           auto label = new QLabel(this);
           QModelIndex index = model()->index(row, i);
           label->setText(model()->data(model()->index(row, i);, Qt::DisplayRole).toString()); // this has HTML
           label->setWordWrap(true);
           setIndexWidget(model()->index(row, i);, label); // this calls QAbstractItemView::dataChanged
       }
}
