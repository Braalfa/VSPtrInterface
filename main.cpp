#include "mainwindow.h"
#include <QApplication>

/**
 * Muestra la pantalla principal del programa
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
