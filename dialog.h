#ifndef DIALOG_H
#define DIALOG_H
#include <QLineEdit>

#include "QDialogButtonBox"
#include "QDialog"
#include "client.h"
#include "GarbageCollector.h"

#include <QRadioButton>



namespace Ui {
    class Dialog;
}
/**
 * Ventana que se abre para escribir los parametros del servior ip,el puerto la contraseña...
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent, Client *client);
    bool connectionSucces;
    ~Dialog();
private:
    Ui::Dialog *ui;
    QLineEdit *ip;
    QLineEdit *port;
    QLineEdit *user;
    QLineEdit *pass;
    Client *client;
    QRadioButton *localBtn;
    QRadioButton *remoteBtn;
    QDialogButtonBox *box;
    bool testPort();

private slots:
    int setSettings();
};

#endif // DIALOG_H
