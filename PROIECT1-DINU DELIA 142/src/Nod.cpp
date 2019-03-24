#include "Nod.h"

Nod::Nod()
{
    info = 0;
    next = this;
}

Nod::Nod(int i)
{
    info = i;
    next = this;
}

void Nod::setInfo(int i) {
	info = i;
}

void Nod::setNext(Nod* n) {
	next = n;
}

int Nod::getInfo() {
	return info;
}

Nod* Nod::getNext() {
	return next;
}
