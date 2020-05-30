#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent, Client clientOfServer) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    client=clientOfServer;
    ui->setupUi(this);
    ip=ui->ip;
    port=ui->port;
    user=ui->user;
    pass=ui->pass;
    box=ui->box;
    box->
    connect(box, SIGNAL (accepted()),this, SLOT (setSettings()));
}

void Dialog::setSettings(){
    client.setServer(ip->text().toUtf8().constData(), port->text().toUtf8().constData(),
                     user->text().toUtf8().constData(), pass->text().toUtf8().constData());
}


Dialog::~Dialog()
{
    delete ui;
}
