/**
 * \file funckja.h
 * \brief Plik nagłówkowy modułu \a funkcja.
 *
 * Moduł \a funkcja zawiera definicję struktury tablica oraz ListaTablic
 * oraz zestaw funkcji.
 *
 * \see funckje.cpp
 */

#ifndef FUNKCJE
#define FUNKCJE
#include <string>
using namespace std;
/** Główna struktura tworząca dwuwymiarowe tablice.
 */
struct tablica
{
    bool komorka;  /**< Pole przechowujące wartość logiczną potrzebną do oceny czy istnieje dana komórka
 */
    char znak;  /**< Pole przechowujące znak który pokazywany zostaje na konsoli w formie:
*   X istnieje komórka
*   0 nie istnieje (wartość logiczna 0)
*   @ komórka literacje temu istniała teraz już nie.
*/
};
/** Główna struktura potrzebna do stworzenia jednokierunkowej listy tablic.
 */
struct ListaTablic
{
    tablica **tab;  /**< Pole przechowujące dwuwymiarowe tablice dynamiczne */
    ListaTablic *nast;   /**< Pole przechowujące wskaźnik do następnego elementy listy. */
};
/**
 * Funkcja tworząca nową tablice.
 *
 * @param c rozmiar tablicy dwuwymiarowej.
 * @return gotowa Tablica.
 */
tablica **Nowa(int c);
/**
 * Funkcja czekaj
 *
 * @param seconds sekundy które dla których program będzie czekał.
 */
void wait(int seconds);

/**
 * Procedura główna na zasadach gra w życie:
 *  W grze w życie, dla każdej komórki sprawdzana jest liczba aktywnych komórek sąsiadujących z daną wg sąsiedztwa Moore'a. Może ich być od 0 do 8. Nowy stan komórki wyznacza następująca reguła:
 *
* Jeśli jest nieaktywna i dokładnie 3 sąsiednie są aktywne, staje się aktywna.
* Jeśli jest aktywna i 2 lub 3 sąsiednie są aktywne, pozostaje aktywna.
* W przeciwnym wypadku staje się nieaktywna. [2]
 * @param **T dwuwymiarowa tablica dynamiczna
 * @param c rozmiar tablicy dwuwymiarowej
 * @return gotowa Tablica.
*/
tablica  **funkcja(tablica **T,int c);
/**
 * Funkcja losująca tablice.
 *
 *  @param  **T dwuwymiarowa tablica dynamiczna
 * @param c rozmiar tablicy dwuwymiarowej.
 *  @return gotowa Tablica.
 */

void losuj(tablica **T,int c);

/**
 * Procedura która zapisuje Tablice do pliku
 * zapisuje tablice do listy kierunkowej
 *
 * @param nazwa nazwa pliku
 * @param **T dwuwymiarowa tablica dynamiczna
 * @param c rozmiar tablicy dwuwymiarowej
 *
 */
void zapiszdo(string nazwa,tablica **T,int c);
/**
 * Procedura która używa wczytuje z pliku tablice
 *
 * @param nazwa nazwa pliku
 * @param c rozmiar tablicy dwuwymiarowej, zostaje rekurencyjnie wczytany z pliku
 @param p wartosc logincza decydujaca o poprawnosci pliku
 */
tablica  **wczytaj(string nazwa, int &c, bool &p);
/**
 * Funkcja która zapisuje liste do pliku
 *
 * @param nazwa nazwa pliku
 * @param *Lista Lista którą zapisujemy do pliku
 * @param c rozmiar tablicy dwuwymiarowej
 * @return gotowa Tablica.
 */
void zapiszListe(string nazwa,ListaTablic *Lista,int c) ;
/**
 * Procedura która usuwa Liste
 *
 * @param *L Lista która ma zostać usunięta
 */
void usunListe(ListaTablic *L);

#endif // FUNKCJE

