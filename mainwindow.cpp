/**
 * \file mainwindow.cpp
 * \brief Plik implementacji modułu \a mainwindow.
 *
 * Moduł \a mainwindow zawiera definicję klasy MainWindow oraz
 *  zestaw funkcji.
 *
 * \see mainwindow.h
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    k=0;
    istniejeLista=false;
    istniejetablica=false;
}

MainWindow::~MainWindow()
{   usunListe(Lista);
    delete Lista;
    delete K;
    delete ui;

}

void MainWindow::on_pushZatwierdz_clicked()
{       ui->naszaplansza->clear();
        if(ui->checkWczytaj->isChecked())
        {   istniejetablica=true;
            K=wczytaj(ui->nazwaplanszy->text().toStdString(),k,t);
            ui->nazwaplanszy->clear();
            if(t)
            Wypiszfunckja(K,k);
            else {
               msgBox.setText("Plik jest nieprawidlowy");
               msgBox.exec();
            }}
            else
            {
        if(k<1)
        {
            msgBox.setText("Prosze ustawic rozmiar planszy");
            msgBox.exec();
        }
        else {
           istniejetablica=true;

    if(ui->checkLosuj->isChecked())
    {
        losuj(K,k);
        Wypiszfunckja(K,k);
    }
    if(ui->checkUtworz->isChecked())
    {
         Wypiszfunckja(K,k);
    }

    }

}
}
void MainWindow::Wypiszfunckja(tablica **T, int l)
    {   QChar znakqt;
        QString tekst;
        char znakz;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {   znakz=T[i][j].znak;
          znakqt=znakz;
            tekst.append(znakqt);
            tekst.append(" ");

        }
        ui->naszaplansza->append(tekst);
        tekst.clear();
    }
}

void MainWindow::on_pushRozmiar_clicked()
{
    k=ui->spinRozmiar->value();
    if(k>0)
       {
    K=Nowa(k);
    }
    if(k<1)
    {
        msgBox.setText("Prosze podac liczbe wieksza od zera");
        msgBox.exec();
    }
}

void MainWindow::on_pushButton_clicked()
{    int numerwiersza,numerkolumny;
     numerwiersza=ui->spinNumerwiersza->value();
     numerwiersza--;
     numerkolumny=ui->spinNumerKolumny->value();
     numerkolumny--;
    if(numerwiersza<0||numerwiersza>k)
    {
        msgBox.setText("Prosze podac liczbe dodatnia, nieprzekraczajaca rozmiaru planszy");
        msgBox.exec();
    }
    else {
        if(numerkolumny<0||numerkolumny>k)
        {
            msgBox.setText("Prosze podac liczbe dodatnia, nieprzekraczajaca rozmiaru planszy");
            msgBox.exec();
        }
        else
        {     K[numerwiersza][numerkolumny].komorka=true;
            K[numerwiersza][numerkolumny].znak='X';
    ui->spinNumerKolumny->clear();
    ui->spinNumerwiersza->clear();
}}}

void MainWindow::on_pushZapisz_clicked()
{   if(istniejetablica)
    {
    zapiszdo(ui->lineEditZapisz->text().toStdString(),K,k);
    ui->lineEditZapisz->clear();
}
    else {
       msgBox.setText("Najpierw Prosze utworzyc plansze");
        msgBox.exec();
    }
}

void MainWindow::on_pushPomoc_clicked()
{   ui->gotowaPlansza->clear();
    QString halp;
    halp="W grze w zycie, dla kazdej komorki sprawdzana jest liczba aktywnych komorek sasiadujacych z dana wg sasiedztwa Moore'a. Moze ich byc od 0 do 8. Nowy stan komorki wyznacza nastepujaca regula: ";
    ui->gotowaPlansza->append(halp);
    halp="    ";
    ui->gotowaPlansza->append(halp);
    ui->gotowaPlansza->append(halp);
    halp="1.  Jesli jest nieaktywna i dokladnie 3 sasiednie sa aktywne, staje sie aktywna.";
    ui->gotowaPlansza->append(halp);
    halp="2.  Jesli jest aktywna i 2 lub 3 sasiednie sa aktywne, pozostaje aktywna.";
    ui->gotowaPlansza->append(halp);
    halp="3.  W przeciwnym wypadku staje sie nieaktywna.";
    ui->gotowaPlansza->append(halp);
    halp="Znak X oznacza aktywna komorke";
    ui->gotowaPlansza->append(halp);
    halp="Znak O oznacza nieaktywna komorke";
    ui->gotowaPlansza->append(halp);
    halp="Znak @ oznacza nieaktywna komorke ktora w poprzedniej literacji byla aktywna";
    ui->gotowaPlansza->append(halp);

}

void MainWindow::on_pushUruchom_clicked()
{   if(istniejetablica)
    {
    int ile=ui->spinLiczba->value();
    if(ile<1)
    {
        msgBox.setText("Prosze podac liczbe dodatnia, wieksza od zera");
        msgBox.exec();
    }
    else
    {   istniejeLista=true;
    ui->gotowaPlansza->clear();
    Lista=new ListaTablic;
      Lista->tab=K;
    for(int i=0;i<ile;i++)
    {   ui->gotowaPlansza->append(" ");

        K=funkcja(K,k);
        Lista->nast=new ListaTablic;
        Lista->nast=Lista;
          Lista->tab=K;
          Lista->nast=NULL;
       QChar znakqt;
              QString tekst;
              char znakz;
          for(int i=0;i<k;i++)
          {
              for(int j=0;j<k;j++)
              {   znakz=K[i][j].znak;
                znakqt=znakz;
                  tekst.append(znakqt);
                  tekst.append(" ");

              }
              ui->gotowaPlansza->append(tekst);
              tekst.clear();

    }
}
}}
    else {
       msgBox.setText("Najpierw Prosze utworzyc plansze");
       msgBox.exec();
    }
}

void MainWindow::on_pushLista_clicked()
{   if(istniejeLista)     
    zapiszListe(ui->lineLista->text().toStdString(),Lista,k);
    else {
       msgBox.setText("Prosze stworzyc liste przed zapisaniem jej do pliku");
       msgBox.exec();
    }
    ui->lineLista->clear();
    }
