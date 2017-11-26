#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#include "main.h"

#define firstA(P) P.firstA
#define lastA(P) P.lastA
#define nextA(P) P->nextA
#define prevA(P) P->prevA
#define infoA(P) P->infoA

typedef struct elmA *addressA;
struct elmA{
    string infoA;
    addressA nextA;
    addressA prevA;
};
struct ListA{
    addressA firstA;
    addressA lastA;
};

void createListA(ListA &);
addressA alokasiA(string);

void infiA(ListA &, addressA);
void inlaA(ListA &, addressA);
void inafA(ListA &, addressA, addressA);

void delfiA(ListA &, addressA &);
void dellaA(ListA &, addressA &);
void delafA(ListA &, addressA, addressA &);

void inAscA(ListA &, addressA);
void deleteA(ListA &, string);

addressA findElmA(ListA, string);
void printInfoA(ListA);

#endif // ACTOR_H_INCLUDED
