/**
* \file funckje.cpp
* \brief Plik implementacji modułu \a funckje.
*
* Moduł \a funkcja zawiera definicję struktury tablica oraz ListaTablic
* oraz zestaw funkcji.
*
* \see funkcje.h
*/
#include "funkcje.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <time.h>

using namespace std;

tablica **Nowa(int c)
{
    tablica **T;
    T=new tablica*[c];
    for(int i=0;i<c;i++)
    {
        T[i]=new tablica[c];
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
        {
            T[i][j].komorka=false;
            T[i][j].znak='O';
        }
    }
    return T;
}
void wait(int seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}


tablica  **funkcja(tablica **T,int c)
{   tablica **A;
    A=Nowa(c);
    int ile=0;                                        /// \note lewy róg
    if(T[0][1].komorka==true)
        ile++;
    if(T[1][1].komorka==true)
        ile++;
    if(T[1][0].komorka==true)
        ile++;
    if(ile==3)
    {  A[0][0].komorka=true;
       A[0][0].znak='X'; }
    if(ile==2&&T[0][0].komorka==true)
      {  A[0][0].komorka=true;
         A[0][0].znak='X'; }
    if(ile<2)
       { A[0][0].komorka=false;
        if(T[0][0].komorka==true)
            A[0][0].znak='@';
    }
    if(ile>3)
    { A[0][0].komorka=false;
     if(T[0][0].komorka==true)
         A[0][0].znak='@';
 }
    ile=0;                                        /// \note prawy róg
    if(T[c-2][0].komorka==true)
        ile++;
    if(T[c-2][1].komorka==true)
        ile++;
    if(T[c-1][1].komorka==true)
        ile++;
    if(ile==3)
    {  A[c-1][0].komorka=true;
       A[c-1][0].znak='X'; }
    if(ile==2&&T[c-1][0].komorka==true)
      { A[c-1][0].komorka=true;
        A[c-1][0].znak='X'; }
    if(ile<2)
       { A[c-1][0].komorka=false;
        if(T[c-1][0].komorka==true)
            A[c-1][0].znak='@';
    }
    if(ile>3)
    { A[c-1][0].komorka=false;
     if(T[c-1][0].komorka==true)
         A[c-1][0].znak='@';
 }
     ile=0;                                        /// \note prawy róg dolny
    if(T[c-2][c-1].komorka==true)
        ile++;
    if(T[c-2][c-2].komorka==true)
        ile++;
    if(T[c-1][c-2].komorka==true)
        ile++;
    if(ile==3)
    {  A[c-1][c-1].komorka=true;
       A[c-1][c-1].znak='X'; }
    if(ile==2&&T[c-1][c-1].komorka==true)
      { A[c-1][c-1].komorka=true;
        A[c-1][c-1].znak='X'; }
    if(ile<2)
       { A[c-1][c-1].komorka=false;
        if(T[c-1][c-1].komorka==true)
            A[c-1][c-1].znak='@';
    }
    if(ile>3)
    { A[c-1][c-1].komorka=false;
     if(T[c-1][c-1].komorka==true)
         A[c-1][c-1].znak='@';
 }
     ile=0;                                        ///  \note lewy róg dolny
    if(T[0][c-2].komorka==true)
        ile++;
    if(T[1][c-2].komorka==true)
        ile++;
    if(T[1][c-1].komorka==true)
        ile++;
    if(ile==3)
    {  A[0][c-1].komorka=true;
       A[0][c-1].znak='X'; }
    if(ile==2&&T[0][c-1].komorka==true)
      { A[0][c-1].komorka=true;
        A[0][c-1].znak='X'; }
    if(ile<2)
       { A[0][c-1].komorka=false;
        if(T[0][c-1].komorka==true)
            A[0][c-1].znak='@';
    }
    if(ile>3)
    { A[0][c-1].komorka=false;
     if(T[0][c-1].komorka==true)
         A[0][c-1].znak='@';
 }

for(int i=1;i<c-1;i++)           /// \note pierwsza górna linia
{    ile=0;
    if(T[i-1][0].komorka==true)
        ile++;
    if(T[i][1].komorka==true)
        ile++;
    if(T[i-1][1].komorka==true)
        ile++;
    if(T[i+1][1].komorka==true)
        ile++;
    if(T[i+1][0].komorka==true)
        ile++;
    if(ile==3)
    {  A[i][0].komorka=true;
       A[i][0].znak='X'; }
    if(ile==2&&T[i][0].komorka==true)
      { A[i][0].komorka=true;
        A[i][0].znak='X'; }
    if(ile<2)
       { A[i][0].komorka=false;
        if(T[i][0].komorka==true)
            A[i][0].znak='@';
    }
    if(ile>3)
    { A[i][0].komorka=false;
     if(T[i][0].komorka==true)
         A[i][0].znak='@';
 }

}
for(int i=1;i<c-1;i++)           /// \note pierwsza lewa linia
{    ile=0;
    if(T[0][i-1].komorka==true)
        ile++;
    if(T[1][i-1].komorka==true)
        ile++;
    if(T[1][i].komorka==true)
        ile++;
    if(T[1][i+1].komorka==true)
        ile++;
    if(T[0][i+1].komorka==true)
        ile++;
    if(ile==3)
    {  A[0][i].komorka=true;
       A[0][i].znak='X'; }
    if(ile==2&&T[0][i].komorka==true)
      { A[0][i].komorka=true;
        A[0][i].znak='X'; }
    if(ile<2)
       { A[0][i].komorka=false;
        if(T[0][i].komorka==true)
            A[0][i].znak='@';
    }
    if(ile>3)
    { A[0][i].komorka=false;
     if(T[0][i].komorka==true)
         A[0][i].znak='@';
 }

}
for(int i=1;i<c-1;i++)           /// \note pierwsza prawa linia
{    ile=0;
    if(T[c-1][i-1].komorka==true)
        ile++;
    if(T[c-2][i-1].komorka==true)
        ile++;
    if(T[c-2][i].komorka==true)
        ile++;
    if(T[c-2][i+1].komorka==true)
        ile++;
    if(T[c-1][i+1].komorka==true)
        ile++;
    if(ile==3)
    {  A[c-1][i].komorka=true;
       A[c-1][i].znak='X'; }
    if(ile==2&&T[c-1][i].komorka==true)
      { A[c-1][i].komorka=true;
        A[c-1][i].znak='X'; }
    if(ile<2)
       { A[c-1][i].komorka=false;
        if(T[c-1][i].komorka==true)
            A[c-1][i].znak='@';
    }
    if(ile>3)
    { A[c-1][i].komorka=false;
     if(T[c-1][i].komorka==true)
         A[c-1][i].znak='@';
 }

}
for(int i=1;i<c-1;i++)           /// \note pierwsza dolna linia
{    ile=0;
    if(T[i-1][c-1].komorka==true)
        ile++;
    if(T[i-1][c-2].komorka==true)
        ile++;
    if(T[i][c-2].komorka==true)
        ile++;
    if(T[i+1][c-2].komorka==true)
        ile++;
    if(T[i+1][c-1].komorka==true)
        ile++;
    if(ile==3)
    {  A[i][c-1].komorka=true;
       A[i][c-1].znak='X'; }
    if(ile==2)
      { if(T[i][c-1].komorka==true)
        {
        A[i][c-1].komorka=true;
        A[i][c-1].znak='X'; }}
    if(ile<2)
       { A[i][c-1].komorka=false;
        if(T[i][c-1].komorka==true)
            A[i][c-1].znak='@';
    }
    if(ile>3)
    { A[i][c-1].komorka=false;
     if(T[i][c-1].komorka==true)
         A[i][c-1].znak='@';
 }

}
for(int i=1;i<c-1;i++)                 /// \note dla pozostałych i;
{
   for(int j=1;j<c-1;j++)
   {
        ile=0;
           if(T[i-1][j-1].komorka==true)
               ile++;
           if(T[i-1][j].komorka==true)
               ile++;
           if(T[i-1][j+1].komorka==true)
               ile++;
           if(T[i][j+1].komorka==true)
               ile++;
           if(T[i][j-1].komorka==true)
               ile++;
           if(T[i+1][j-1].komorka==true)
               ile++;
           if(T[i+1][j].komorka==true)
               ile++;
           if(T[i+1][j+1].komorka==true)
               ile++;
           if(ile==3)
           {  A[i][j].komorka=true;
              A[i][j].znak='X'; }
           if(ile==2)
          { if(T[i][j].komorka==true)
           { A[i][j].komorka=true;
               A[i][j].znak='X'; } }
           if(ile<2)
              { A[i][j].komorka=false;
               if(T[i][j].komorka==true)
                   A[i][j].znak='@';
           }
           if(ile>3)
           { A[i][j].komorka=false;
            if(T[i][j].komorka==true)
                A[i][j].znak='@';
        }
   }
}
 return A;



}
void losuj(tablica **T,int c)
{   int k;
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
        {
           k=rand()%2;
            if(k==0)
            {    T[i][j].komorka=false;
                 T[i][j].znak='O';
            }
            if(k==1)
            {    T[i][j].komorka=true;
                 T[i][j].znak='X';
            }

        }
    }



}



void zapiszdo(string nazwa, tablica **T, int c)        // zapis tablicy do pliku
{
    ofstream plik;
    plik.open(nazwa.c_str());
    plik<<c<<" ";
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
        {
            plik<<T[i][j].znak<<" ";
        }
    } plik.close();
}

void usunListe(ListaTablic *L)
{   while(L!=0)
    {
        ListaTablic *p=L;
        L=L->nast;
        delete p->tab;
        delete p;
    }

}

tablica  **wczytaj(string nazwa, int &c, bool &p)                      // wczytywanie tablicy z pliku
{   ifstream plik;
        string tekst;
        plik.open(nazwa.c_str());
        plik>>tekst;
        c=atoi(tekst.c_str());
        if(c<=0)
        {
            p=false;
        }
        else
            p=true;

        tablica **T;
        T=new tablica*[c];
        for(int i=0;i<c;i++)
        {
            T[i]=new tablica[c];
        }

     for(int i=0;i<c;i++)
     {
         for(int j=0;j<c;j++)
         {
             plik>>T[i][j].znak;

             if(T[i][j].znak=='X')
                 T[i][j].komorka=true;
             else
                  T[i][j].komorka=false;
         }
}
     plik.close();
     return T;
}
void zapiszListe(string nazwa,ListaTablic *Lista,int c)           // zapis listy do pliku
{
   ofstream plik;
   plik.open(nazwa.c_str());
   while(Lista->nast!=NULL)
   {
       for(int i=0;i<c;i++)
       {
           for(int j=0;j<c;j++)
           {
               plik<<Lista->tab[i][j].znak<<" ";
           }
       }
       plik<<endl;
       Lista=Lista->nast;
   }
   plik.close();
}

