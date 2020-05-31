#ifndef MEMORYVIEW_H
#define MEMORYVIEW_H


class QLabel;

class MemoryView : public QTableView {
       Q_OBJECT

public:
       explicit MemoryView(QWidget *parent = 0);

       void rowsInserted(const QModelIndex &parent, int start, int end);

private:
       void insertLabels(int row);
       void removeLabels(int row);
};
