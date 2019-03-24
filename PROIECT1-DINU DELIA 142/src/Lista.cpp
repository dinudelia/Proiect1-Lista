#include "Lista.h"
#include<iostream>

using namespace std;


Lista::Lista()
{
    start = end = NULL; //lista vida
    size = 0;
}


Lista::Lista(int x)
{
    start = end = new Nod(x); //aloc memorie pentru un nod
    size = 1;                 //lista cu un element
}



Nod* Lista::getstart()
{
    return start;   //returnez nodul start
}


Nod* Lista::getend()
{
    return end;   //returnez nodul end
}


void Lista::setsize(int x)
{
    size=x;         //resetez numarul de elemente ale listei cu valoarea x
}


void Lista::setstart(Nod *p)
{
    start->setInfo(p->getInfo());   // resetez informatia din start
    start->setNext(p->getNext());   // resetez urmatorul nod
}

void Lista::setend(Nod *p)
{
    end->setInfo(p->getInfo());   //resetez informatia din start
    end->setNext(p->getNext());   // resetez umratorul nod

}

Lista::~Lista()
{
    Nod *p = start, *o;
    for(int i=0; i<size; i++)
    {
        o = p;                   //parcurg lista si sterg fiecare nod al acesteia
        p = p->getNext();
        delete o;
    }
    start = end = NULL;         //lista vida
    size = 0;

}

void Lista::afisare()
{
    Nod *p = start;

    for(int i=0; i<size; i++)
    {
        cout << p->getInfo() << " ";   //parcurg lista si afisez informatia fiecarui nod
        p = p->getNext();
    }
    cout << endl;
}


void Lista:: inserare(int x)
{
    Nod *p=new Nod(x);   //aloc memorie pentru un nou nod
    p->setNext(start);   //fac legatura dintre noul nod si nnodul start
    if(size==0)
    {
        start=end=p;      //daca lista este vida
        size++;
    }
    else
    {
        end->setNext(p);   // legatura end-start
        end=p;            // ultimul nod devine ultimmul p
        size++;
    }
}


void Lista::stergere(int i)
{
    if (i < 0 || i >= size)
    {
        return;                //daca i este mai mic sau egal decat numar de elemente din lista parasesc metoda
    }
    Nod* p = start;
    if (i == 0)
    {
        if (size == 1||size==0)
        {
            delete p;               // daca lista este vida sau are un singur element, resetez  end si start la null si sterg nodul p
            end = start = NULL;     // lista ramane/devine vida

        }
        else
        {
            start = start->getNext();   // start devine nodul urmator si sterg nodul p
            delete p;
        }
    }
    else
    {
        for (int j = i; j > 1; j--)
        {
            p = p->getNext();  //parcurg lista pana ajung la pozitia i-1
        }
        Nod* o = p->getNext();    // retin adresa nodului de pe pozitia i
        p->setNext(o->getNext());  // se face legatura intre i-1 si i+1
        delete o;                   // sterg nodul de pe pozitia i
    }
    size--;
}



Lista::Lista(Lista& l)
{
    start = end = NULL;
    size = 0;
    Nod* p = l.getstart();       // pun in nodul p startul din lista pe care o copiez
    for(int i=0; i<l.nrelemente(); i++)
    {
        (*this).inserare(p->getInfo());   // parcurg lista l si inserez fiecare element din lista l in noua lista
        p = p->getNext();
    }
}


void Lista::inserarepoz(int x, int i)
{
    if (start == NULL)
    {
        start = end = new Nod(x);    //daca lista este vida aloc memorie pentru un nod
        (*this).size = 1;

    }
    else
    {
        Nod* p = new Nod(x);  //aloc memorie pentru un nou nod
        if (i == 0)
        {
            p->setNext(start);   //daca inserez pe prima pozitie fac legatura dintre fostul start si noul nod care devine start
            start = p;           // start devine p
            return;
        }
        if (i < 0 || i >= size)
        {
            end->setNext(p);   //daca i este mai mare ca numarul de elemente sau este numar negativ, inserez la sfarsit
            end = p;           // fac legatura dintre ultimul nod si noul nod si end devine noul nod
            size++;
            return;
        }
        Nod* o = start;
        for (int j = i; j > 1; j--)
        {
            o = o->getNext();    // parcurg lista pana la pozitia i-1
        }
        p->setNext(o->getNext());   // fac legatura dintre noul nod si nodul care a fost pe pozitia i
        o->setNext(p);              // fac legura dintre nodul de pe pozitia i-1 si noul nod
        size++;
    }
}



int Lista:: cautare(int x)
{
    int i;
    Nod *p=start;
    for(i=0; i<size; i++)
    {
        if(p->getInfo()==x)  //parcurg lista si in cazul in care gasesc elementul cautat returnez 1
            return 1;
        p=p->getNext();
    }
    return 0;
}


unsigned Lista::nrelemente()
{
    return size;         //returnez numarul de elementele din lista
}

int Lista:: sumaelemente()
{

    int i,s=0;
    Nod *p=start;
    for(i=0; i<size; i++)
    {
        s=s+p->getInfo();  //parcurg lista si adaug fiecare element in suma la fiecare pas
        p=p->getNext();
    }

    return s;

}

int Lista:: maxim( )
{
    int max;
    Nod *p=start;
    max=p->getInfo();    //initializez maximul cu primul element
    int i;
    for(i=0; i<size; i++)
    {
        if(p->getInfo()>max)
            max=p->getInfo();   //parcurg lista si la fiecare pas verific la elementul curent este mai mare decat maximul
        p=p->getNext();
    }

    return max;

}

int Lista:: minim( )
{
    int min;
    Nod *p=start;
    min=p->getInfo();
    int i;
    for(i=0; i<size; i++)
    {
        if(p->getInfo()<min)     ////parcurg lista si la fiecare pas verific la elementul curent este mai mare decat minimul
            min=p->getInfo();
        p=p->getNext();
    }

    return min;

}


Lista& Lista::inversare()
{

    Lista *mylist=new Lista;   //aloc memorie pentru o noua lista
    Nod *p=start;
    Nod *o;
    for(int i=0; i<size; i++)
    {
        if((*mylist).size==0)
        {
            (*mylist).inserare(p->getInfo());  // daca sunt la primul pas pun primul element in lista
        }
        else
        {
        o=new Nod(p->getInfo());          //aloc memorie pentru un nou nod
            o->setNext((*mylist).start);  // fac legatura dintre noul nod si start
            (*mylist).start=o;            //noul nod devine start
            (*mylist).size++;
        }
        p=p->getNext();
    }
    delete p;
    delete o;
    return *mylist;

}


Lista& Lista::operator=(const Lista &l)
{

    int i;
    Nod *p=(*this).start;
    if((*this).size!=0)
    {
        Nod *o;
        for(i=0; i<(*this).size; i++)   //daca lista nu este vida, sterg toate elementele din aceasta
        {
            o=p->getNext();
            delete p;
            p=o;
        }
        delete o;
    }

    (*this).start=(*this).end=NULL;   //lista devine vida
    (*this).size=0;
    p=l.start;
    for(i=0; i<l.size; i++)
    {

        (*this).inserare(p->getInfo());    // parcurg lista l si inserez fiecare element in lista curenta
        p=p->getNext();
    }



    return *this;
}


istream& operator>>(istream &in,Lista &mylist)
{


    Nod *p=mylist.getstart();
    if(mylist.nrelemente()!=0)
    {
        Nod *o;
        for(int i=0; i<mylist.nrelemente(); i++)
        {
            o=p->getNext();             //daca lista pe care doresc sa o citesc are deja elemente, le sterg
            delete p;
            p=o;
        }
        delete o;
    }
    mylist.setsize(0);

    int new_size;
    in>>new_size;                 // lungimea care doresc sa o aiba lista
    int x;
    for(int i=0; i<new_size; i++)
    {
        in>>x;
        mylist.inserare(x);        //inserez fiecare valoare citita in lista
    }

    return in;
}

ostream& operator<<(ostream &out, Lista mylist)
{
    for(int i=0; i<mylist.nrelemente(); i++)     //parcurg lista si la fiecare pas afisez emenetul curent
        out<<mylist[i]<<" ";
    return out;
}


int Lista :: operator [](int j)
{
    Nod *p=start;
    int i;
    for(i=0; i<size; i++)
    {

        if(i==j)
        {

            return p->getInfo();      //parcurg lista pana gasesc pozitia pe care mi-o gasesc si return valoarea de pe pozitia respectiva
        }
        p=p->getNext();
    }
    return -1;                    // in cazul in care nu gasesc pozitia, returnez -1
}


Lista& Lista:: operator*(int x)
{
    Lista *mylist =new Lista;   // aloc memorie pentru o noua lista
    Nod *p=start;
    int i,a;

    for(i=0; i< size; i++)
    {

        a=(p->getInfo())*x;      // parcurg lista si la fiecare pas inmultesc elementul curent cu paramestrul
        (*mylist).inserare(a);        //inserez noua valore a elementului in noua lista
        p=p->getNext();
    }

    return *mylist;
}





int Lista:: operator>(Lista j)
{
    if(sumaelemente()>j.sumaelemente())
        return 1;
    return 0;
}


int Lista:: operator<(Lista j)
{
    if(sumaelemente()<j.sumaelemente())
        return 1;
    return 0;
}

Lista &Lista:: operator+( Lista lista_2)
{
    Lista *mylist=new Lista;    // aloc memorie pentru o noua lista
    Nod *p=start;
    int i;
    for(i=0; i<size; i++)
    {
        (*mylist).inserare(p->getInfo());  // parcurg prims lista si inserez fiecare element in noua lista
        p=p->getNext();

    }

    p=lista_2.getstart();
    for(i=0; i< lista_2.size; i++)
    {

        (*mylist).inserare(p->getInfo());  //parcurg cea de-a doua lista (cea transmisa ca paramestru) si inserez fiecare element in noua lista
        p=p->getNext();

    }

    return *mylist;

}



