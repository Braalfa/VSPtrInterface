#include "dialog.h"
#include <QMessageBox>
#include <QRadioButton>
#include "ui_dialog.h"

/**
 *Abre la ventana donde se modifican los parametros
 * @param parent
 * @param client
 */
Dialog::Dialog(QWidget *parent,  Client *client):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ip=ui->ip;
    port=ui->port;
    user=ui->user;
    pass=ui->pass;
    box=ui->box;

    this->client=client;
    this->connectionSucces=false;

    box->connect(box, SIGNAL (accepted()),this, SLOT (setSettings()));
}
/**
 * Modifica los labels segun el valor que ponemos en el label para la creacion del servidor
 * @return
 */
int Dialog::setSettings(){
    int result=-1;
    if(testPort()){
        client->setServer(ip->text().toUtf8().constData(), port->text().toUtf8().constData(),
                         user->text().toUtf8().constData(), pass->text().toUtf8().constData());
        result =client->logIn();
    }
    QMessageBox message;
    if(result=-1){
        message.setIcon(QMessageBox::Warning);
        message.setText("Connection Failed");
        message.exec();
        this->connectionSucces=false;
    }
    this->connectionSucces=true;
}

bool Dialog::testPort()
{
    string s=port->text().toUtf8().constData();
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
/**
 * Eliminar la ventana del Dialog
 */

Dialog::~Dialog()
{
    delete ui;
}
