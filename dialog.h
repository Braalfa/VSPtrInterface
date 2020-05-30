#ifndef DIALOG_H
#define DIALOG_H
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDialog>
#include "client.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent, Client client);
    ~Dialog();
private:
    Ui::Dialog *ui;
    QLineEdit *ip;
    QLineEdit *port;
    QLineEdit *user;
    QLineEdit *pass;
    QDialogButtonBox *box;
    Client client;
private slots:
    void setSettings();
};

#endif // DIALOG_H
