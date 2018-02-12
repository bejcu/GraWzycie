/**
 * \file mainwindow.h
 * \brief Plik nagłówkowy modułu \a mainwindow.
 *
 * Moduł \a mainwindow zawiera definicję klasy MainWindow oraz
 *  zestaw funkcji.
 *
 * \see mainwindow.cpp
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <funkcje.h>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    /** Procedura którą uruchamia przycisk "pushZatwierdz"
     * tworzy nowa plansze
     */
    void on_pushZatwierdz_clicked();
    /** Procedura która wypisuje tablice w oknie w polu nasza plansza "naszaplansza"
     * @param **T dwuwymiarowa tablica dynamiczna
     * @param l rozmiar tablicy dwuwymiarowej
     */
    void Wypiszfunckja(tablica **T, int l);
    /** Procedura którą uruchamia przycisk "pushRozmiar"
     * zatwierdza rozmiar tablicy.
     */
    void on_pushRozmiar_clicked();
    /** Procedura którą uruchamia przycisk "pushButton"
     * dodaje elementy do tablicy
     */
    void on_pushButton_clicked();
    /** Procedura którą uruchamia przycisk "pushZapisz"
     * zapisuje plansze do pliku
     */
    void on_pushZapisz_clicked();
    /** Procedura którą uruchamia przycisk "pushPomoc"
     *  wyswietla potrzebne informacje w polu gotowa plansza"
     */
    void on_pushPomoc_clicked();
    /** Procedura którą uruchamia przycisk "pushUruchom"
     * uruchamia funckje o nazwie "funkcja" i wypisuje gotowa tablice w polu "gotowaplansza"
     */
    void on_pushUruchom_clicked();
    /** Procedura którą uruchamia przycisk "pushLista"
     * zapisuje Liste do pliku podanego przez użytkownika
     */

    void on_pushLista_clicked();

private:
    Ui::MainWindow *ui;
    int k;
    tablica **K;
    bool t;
    QMessageBox msgBox;
    ListaTablic *Lista;
    bool istniejetablica;
    bool istniejeLista;
};

#endif // MAINWINDOW_H
