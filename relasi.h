#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "actor.h"
#include "film.h"

#define firstR(P) P.firstR
#define nextR(P) P->nextR
#define aktor(P) P->aktor
#define film(P) P->film

typedef struct elmR *addressR;

struct elmR{
    addressR nextR;
    addressA aktor;
    addressF film;
};
struct ListR{
    addressR firstR;
};

void createListR(ListR &);

void infiR(ListR &, addressR);
void inlaR(ListR &, addressR);
void inafR(ListR &, addressR, addressR);
void delfiR(ListR &, addressR &);
void dellaR(ListR &, addressR &);
void delafR(ListR &, addressR, addressR &);
void deleteR(ListR &, addressR &);

addressR alokasiR(addressA, addressF);
addressR findElmR(ListR, addressA, addressF);
void printInfoAktorR(ListR, string);
void printInfoFilmR(ListR, string);
#endif // RELASI_H_INCLUDED
