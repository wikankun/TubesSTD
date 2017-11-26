#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include "main.h"

#define nextF(P) P->nextF
#define firstF(L) L.firstF
#define infoF(P) P->infoF
#define judul(P) (P->infoF).judul
#define year(P) (P->infoF).year
#define duration(P) (P->infoF).duration

typedef struct elmF* addressF;
struct infoF{
    string judul;
    int year;
    int duration;
};
struct elmF{
    infoF infoF;
    addressF nextF;
};
struct ListF{
    addressF firstF;
};
void createListF(ListF &L);
addressF alokasiF(infoF x);
void dealokasi(addressF &P);
void infiF(ListF &L,addressF P);
void inlaF(ListF &L,addressF P);
void inafF(ListF &L,addressF prec,addressF P);
addressF findElmF(ListF L,string judul);
void delfiF(ListF &L,addressF &P);
void dellaF(ListF &L,addressF &P);
void delafF(ListF &L, addressF prec, addressF &P);
void deleteF(ListF &L, string judul);
void printInfoF(ListF L);
#endif // FILM_H_INCLUDED
