#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "relasi.h"

void gotoxy(int x, int y);
void DeleteRA(ListR &, ListA &, string);
void DeleteRF(ListR &, ListF &, string);

void menuTambah(ListA &, ListR &, ListF &);
void menuHapus(ListA &, ListR &, ListF &);
void menuView(ListA, ListR, ListF);

#endif // MENU_H_INCLUDED
