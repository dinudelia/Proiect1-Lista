#ifndef LISTA_H
#define LISTA_H
#include "Nod.h"
#include <iostream>
using namespace std;

class Lista
{


    Nod *start, *end;
    unsigned size;
public:
    Lista(); //constructor fara parametri
    Lista(int); //constructor care initializeaza primul element din lista cu parametrul
    Lista(Lista&); // costructorul de copiere
    ~Lista(); //destructor
    void inserare(int ); //metoda care insereaza o valoare la sfarsitul listei
    void inserarepoz(int , int); //metoda care insereaza o valoare pe o anumita pozitie
    void afisare(); //metoda care afiseaza lista
    void stergere(int ); //metoda care sterge un element din lista
    int cautare(int );   //metoda care cauta un element in lista
    unsigned nrelemente(); //metoda care returneaza numarul de elemente din lista
    int sumaelemente(); //metoda care returneaza suma elementelor din lista
    int maxim( ); //metoda care returneaza maximul din lista
    int minim(); //metoda care returneaza minimul din lista
    Lista& inversare(); //metoda care inverseaza lista
    Lista& operator=(const Lista &l); // egaleaza o lista cu alta lista
    Lista& operator*(int ); // inmulteste elemetentele listei cu o valoare
    int operator>(Lista ); // verifica daca suma elementelor unei liste este mai mare decat  suma alteia
    int operator<(Lista ); //verifica daca suma elementelor unei liste este mai mica decat  suma alteia
    int operator [](int ); //returneaza elementul de pe o anumita pozitie
    Lista &operator+( Lista j); //face reuniunea a doua liste
    friend istream & operator>>(istream &in, Lista &mylist); // citeste o lista
    friend ostream & operator<<(ostream &out, Lista mylist); // afiiseaza o lista

    Nod* getstart(); //returneaza nodul start al listei
    Nod* getend();  // returneaza nodul end al listei
    void setsize(int x); //reseteaza numarul de elemente al listei
    void setstart(Nod *p); //reseteaza nodul start al listei
    void setend(Nod *p); //reseteaza nodul end al listei



};

#endif // LISTA_H
