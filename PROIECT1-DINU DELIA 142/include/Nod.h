#ifndef NOD_H
#define NOD_H
#include <iostream>


class Nod
{

    int info;
    Nod *next;
public:
    Nod();  //constructor fara paramestri
    Nod(int); // constructor care initializeaza informatia nodului cu valoarea parametrului
    void setInfo(int); // metoda care reseteaza informatia nodului
	void setNext(Nod*); //metoda care reseteaza urmatorul nod
	int getInfo();    //metoda care returneaza informatia nodului
	Nod* getNext();  // metoda care retunreaza nodul urmator

};

#endif // NOD_H
