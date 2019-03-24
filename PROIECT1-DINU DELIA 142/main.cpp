#include <iostream>
#include "Nod.h"
#include "Lista.h"
#include <cassert>

using namespace std;

int main()
{
    Lista lista_1(4),lista_2;
    lista_1.afisare();
    lista_1.inserare(3);
    assert(lista_1.nrelemente()==2);
    lista_1.inserare(2);
    lista_1.afisare();
    lista_1.inserare(1);
    lista_1.inserare(0);
    lista_1.afisare();
    cout << "sterg elementul de pe prima pozitie si lista devine ";
    lista_1.stergere(0);
    lista_1.afisare();
    assert(lista_1.nrelemente()==4);

    int val;
    cout << "verifica daca o valoare se afla in lista ";
    cin>>val;

    if(lista_1.cautare(val)==1)
        cout << "in lista exista elemetul " << val << endl;
    else
        cout<<"in lista nu exista elemetul "<<val<<endl;
    assert(lista_1.cautare(2)==1);

    cout << "numarul de elemente din lista este " << lista_1.nrelemente() <<endl;
    assert(lista_1.nrelemente()==4);

    cout <<"suma elementelor din lista este " <<lista_1.sumaelemente() <<endl;
    assert(lista_1.sumaelemente()==6);

    cout <<"maximul din lista este " <<lista_1.maxim() <<endl;
    assert(lista_1.maxim()==3);

    cout <<"minimul din lista este " <<lista_1.minim() <<endl;
    assert(lista_1.minim()==0);

    cout <<"elementul de pe pozitia 1 este " <<lista_1[1] <<endl;
    cout<<endl;

    lista_2=lista_1.inversare();
    cout <<"lista inverstata este ";
    lista_2.afisare();


    cout << "citeste un numar si apoi o lista cu atatea elemente ";
    cin >>lista_2;
    cout << "lista este " <<lista_2 <<endl;

    cout <<"lista inmultita cu 5 este "  <<(lista_2 * 5) <<endl;


    if(( lista_1 > lista_2 )== 1)
        cout <<"suma elementelor din lista " <<lista_1 <<"este mai mare decat cea din lista " <<lista_2 <<endl;
    else
        cout <<"suma elementelor din lista " <<lista_2 <<"este mai mare decat cea din lista " <<lista_1 <<endl;
    cout<<endl;


    Lista lista_reuniune;
    lista_reuniune= lista_1 + lista_2;
    cout << "reuniunea dinte lista " <<lista_1 << "si lista " << lista_2 << "este ";
    lista_reuniune.afisare();



    return 0;
}
