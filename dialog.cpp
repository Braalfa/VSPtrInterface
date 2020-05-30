#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, Client clientOfServer) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    client=clientOfServer;
    ui->setupUi(this);
    ip=this->ip;
    port=this->port;
    user=this->user;
    pass=this->pass;
    box=this->box;

    connect(box, SIGNAL (accepted()),this, SLOT (onRemoteBtn()));

}

void Dialog::setSettings(){
    client.setServer(ip->text().toUtf8().constData(), port->text().toUtf8().constData(),
                     user->text().toUtf8().constData(), pass->text().toUtf8().constData());
}

Dialog::~Dialog()
{
    delete ui;
}
