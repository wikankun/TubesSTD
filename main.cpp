#include <string>
#include <cstddef>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

#include "relasi.h"
#include "film.h"
#include "actor.h"
#include "menu.h"

using namespace std;
int main()
{
    ListA LA;
    ListF LF;
    ListR LR;
    createListA(LA);
    createListF(LF);
    createListR(LR);
    addressA A;
    addressF F;
    addressR R;
    infoF x;

    A = alokasiA("Hugh Jackman");
    infiA(LA,A);
    A = alokasiA("Patrick Stewart");
    inAscA(LA,A);
    A = alokasiA("Eddie Redmayne");
    inAscA(LA,A);

    x.judul = "Logan";
    x.duration = 257;
    x.year = 2017;
    F = alokasiF(x);
    infiF(LF,F);

    x.judul = "Les Miserables";
    x.duration = 278;
    x.year = 2012;
    F = alokasiF(x);
    infiF(LF,F);

    x.judul = "Fantastic Beasts";
    x.duration = 253;
    x.year = 2016;
    F = alokasiF(x);
    infiF(LF,F);

    A = findElmA(LA,"Hugh Jackman");
    F = findElmF(LF, "Logan");
    R = alokasiR(A,F);
    infiR(LR,R);
    F = findElmF(LF,"Les Miserables");
    R = alokasiR(A,F);
    infiR(LR,R);F = findElmF(LF,"Fantastic Beasts");
    R = alokasiR(A,F);
    infiR(LR,R);

    A = findElmA(LA,"Patrick Stewart");
    F = findElmF(LF, "Logan");
    R = alokasiR(A,F);
    infiR(LR,R);

    A = findElmA(LA,"Eddie Redmayne");
    F = findElmF(LF, "Les Miserables");
    R = alokasiR(A,F);
    infiR(LR,R);
    F = findElmF(LF,"Fantastic Beasts");
    R = alokasiR(A,F);
    infiR(LR,R);

    printInfoA(LA);
    printInfoF(LF);


    char E = 'A';
    while (E != '0'){
        system("cls");
        cout<<"=============================="<<endl;
        cout<<"=         Menu Utama         ="<<endl;
        cout<<"=============================="<<endl;
        cout<<"= 1. Tambah Data             ="<<endl;
        cout<<"= 2. Hapus Data              ="<<endl;
        cout<<"= 3. View Data               ="<<endl;
        cout<<"=----------------------------="<<endl;
        cout<<"= 0. Keluar                  ="<<endl;
        cout<<"=============================="<<endl;
        cout<<"= Pilihan :                  ="<<endl;
        cout<<"=============================="<<endl;
        gotoxy(12,9);
        E = getch();
        switch(E){
            case '1':
                menuTambah(LA, LR, LF);
                break;
            case '2':
                menuHapus(LA, LR, LF);
                break;
            case '3':
                menuView(LA, LR, LF);
                break;
            case '0':
                char yn='A';
                cout<<"\n\n  Anda Yakin Ingin Keluar? <y/n>";
                while (yn != 'n' && yn != 'y'){
                    yn = getch();
                }
                if (yn=='n'){
                    E = 'A';
                }
                else{
                system("cls");
                cout<<"=================================="<<endl;
                cout<<"=              EXIT              ="<<endl;
                cout<<"=================================="<<endl;
                cout<<"=          Terima Kasih          ="<<endl;
                cout<<"=================================="<<endl;
                }
                break;

        }
    }
    return 0;
}
