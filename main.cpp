/**
 * @mainpage
 * @par Gra w życie
 * Program który generuje komórki na zasadach popularnego programu gra w życie
 * @author Tomasz Durko
 * @date 2015.03.31
 * @version 1.0
*/
/**
 * \file main.cpp
 *
 */
#include "mainwindow.h"
#include <QApplication>
#include "losowanie.h"
#include <form.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow z;
    z.show();
    return a.exec();
}
