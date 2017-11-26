#include "menu.h"

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void DeleteRA(ListR &LR, ListA &LA, string m){
    addressR R = firstR(LR);
    addressA A = findElmA(LA, m);
    addressR prev;
    while (A != nil && R != nil){
        if(aktor(nextR(R))==A){
            prev = R;
            R = nextR(R);
            delafR(LR,prev,R);
        }
        R = nextR(R);
    }
}
void DeleteRF(ListR &LR, ListF &LF, string m){
    addressR R = firstR(LR);
    addressF F = findElmF(LF, m);
    addressR prev;
    while (F != nil && R != nil){
        if(film(nextR(R))==F){
            prev = R;
            R = nextR(R);
            delafR(LR,prev,R);
        }
        R = nextR(R);
    }
}
void menuTambah(ListA &LA, ListR &LR, ListF &LF){
    string newA, newF;
    string Keluar = "B";
    char E = 'A';
    char yn = 'y';
    while (E != 'E'){
        char X = 'A';
        char pilF[50], cari[50];

        while (X != '0' && X != '1' && X != '2' && X != '3'){
            system("cls");
            cout<<"=============================="<<endl;
            cout<<"=          Menu Tambah       ="<<endl;
            cout<<"=============================="<<endl;
            cout<<"= 1. Tambah Aktor/Aktris     ="<<endl;
            cout<<"= 2. Tambah Film             ="<<endl;
            cout<<"= 3. Tambah Relasi           ="<<endl;
            cout<<"=----------------------------="<<endl;
            cout<<"= 0. Back                    ="<<endl;
            cout<<"=============================="<<endl;
            cout<<"= Pilihan :                  ="<<endl;
            cout<<"=============================="<<endl;
            gotoxy(12,9);
            X = getch();
            yn = 'X';
        }
        switch (X){
            case '1':
                while (yn != 'n'){
                    system("cls");
                    cout<<"==============================="<<endl;
                    cout<<"=     Tambah Aktor/Aktris     ="<<endl;
                    cout<<"==============================="<<endl;
                    cout<<"= 0. Back                     ="<<endl;
                    cout<<"= Masukkan Nama Aktor/Aktris : ";
                    cin>>newA;
                    if (newA != "0"){
                        if (findElmA(LA,newA)== nil){
                            infiA (LA,alokasiA(newA));
                            cout<<"Aktor/Aktris Berhasil Ditambahkan"<<endl;
                        } else {
                            cout<<"Aktor/Aktris Sudah Tersedia"<<endl;
                        }

                        cout<<endl;
                        cout<<"Anda Ingin Menambahkan Aktor/Aktris ? <y/n> : ";
                        do{
                            yn = getch();
                        }while (yn != 'y' && yn != 'n');
                    }else {
                        yn = 'n';
                    }
                }
                break;
            case '2':
                while (yn != 'n'){
                    system("cls");
                    cout<<"=============================="<<endl;
                    cout<<"=        Tambah Film         ="<<endl;
                    cout<<"=============================="<<endl;
                    cout<<"= 0. Back                    ="<<endl;
                    cout<<"= Masukkan Film : ";
                    cin>>newF;
                    if (newF != "0"){
                        if (findElmF(LF,newF)== nil){
                            infoF dataF;
                            dataF.judul = newF;
                            cout<<"Masukkan durasi film(menit) : ";
                            cin>>dataF.duration;
                            cout<<"Masukkan tahun film : ";
                            cin>>dataF.year;
                            infiF (LF,alokasiF(dataF));
                            cout<<"Film Berhasil Ditambahkan"<<endl;
                        }else{
                            cout<<"Film Sudah Tersedia"<<endl;
                        }
                        cout<<endl;
                        cout<<"Anda Ingin Menambahkan Film ? <y/n> : ";
                        do{
                            yn = getch();
                        }while (yn != 'y' && yn != 'n');
                    }else{
                        yn = 'n';
                    }
                }
                break;
            case '3':
                while (yn != 'n'){
                    system("cls");
                    cout<<"=============================="<<endl;
                    cout<<"=        Tambah Relasi       ="<<endl;
                    cout<<"=============================="<<endl;
                    printInfoA(LA);
                    cout<<"= 0. Back                    ="<<endl;
                    cout<<"= Pilih Aktor/Aktris : ";
                    cin.getline(cari,50);
                    Keluar = cari;
                    if (Keluar != "0" && Keluar != ""){
                        if (findElmA(LA, cari)== nil){
                            cout<<" Aktor/Aktris "<<cari<<" Belum Tersedia"<<endl;
                        }else{
                            system("cls");
                            cout<<"=============================="<<endl;
                            cout<<"=        Tambah Relasi       ="<<endl;
                            cout<<"=============================="<<endl;
                            printInfoF(LF);
                            cout<<"= 0. Back                    ="<<endl;
                            cout<<"= Pilih Film : ";
                            cin.getline(pilF,50);
                            if (pilF != "0" && pilF != ""){
                                if (findElmF(LF, pilF)== nil){
                                    cout<<" Film "<<pilF<<" Belum Tersedia"<<endl;
                                }else{
                                    if (findElmR(LR,findElmA(LA,cari),findElmF(LF,pilF))==nil){
                                        infiR(LR, alokasiR(findElmA(LA,cari),findElmF(LF,pilF)));
                                        cout<<endl;
                                        cout<<" Film "<<pilF<<" Berhasil Ditambahkan ke Aktor/Aktris "<<cari<<endl;
                                    }else{
                                        cout<<" Film "<<pilF<<" Sudah Tersedia di Data Aktor/Aktris "<<cari<<endl;
                                    }

                                }
                            }else{
                                yn = 'n';
                            }
                        }
                        getch();
                    }else{
                        yn = 'n';
                    }
                }
                break;
            case '0':
                E = 'E';
                break;
    }
  }
}

void menuHapus(ListA &LA, ListR &LR, ListF &LF){
    char E = 'A';
    char yn = 'y';
    while (E != 'E'){
        char X = 'A';
        char cari [50];
        string delafR, Keluar="A";
        while (X != '0' && X != '1' && X != '2' && X != '3'){
            system("cls");
            cout<<"=============================="<<endl;
            cout<<"=         Menu Hapus         ="<<endl;
            cout<<"=============================="<<endl;
            cout<<"= 1. Hapus Aktor/Aktris      ="<<endl;
            cout<<"= 2. Hapus Film              ="<<endl;
            cout<<"= 3. Hapus Relasi            ="<<endl;
            cout<<"=----------------------------="<<endl;
            cout<<"= 0. Back                    ="<<endl;
            cout<<"=============================="<<endl;
            cout<<"= Pilihan :                  ="<<endl;
            cout<<"=============================="<<endl;
            gotoxy(12,9);
            X = getch();
            yn = 'X';
        }
        switch (X){
            case '1':
                while (Keluar != "0"){
                    system("cls");
                    cout<<"==============================="<<endl;
                    cout<<"=     Hapus Aktor/Aktris      ="<<endl;
                    cout<<"==============================="<<endl;
                    printInfoA(LA);
                    cout<<"= 0. Back                     ="<<endl;
                    cout<<"= Hapus Aktor/Aktris : ";
                    cin.getline(cari,50);
                    Keluar = cari;
                    if (Keluar != "0" && Keluar != ""){
                        if (findElmA(LA,cari)== nil){
                            cout<<" Aktor/Aktris "<<cari<<" Belum Tersedia"<<endl;
                        }else{
                            DeleteRA(LR,LA,cari);
                            deleteA(LA,cari);
                            cout<<" Aktor/Aktris "<<cari<<" Berhasil Dihapus"<<endl;
                        }
                        cout<<" Press Any Key To Continue ";
                        getch();
                    }
                }
                break;
            case '2':
                while (Keluar != "0"){
                    system("cls");
                    cout<<"==============================="<<endl;
                    cout<<"=          Hapus Film         ="<<endl;
                    cout<<"==============================="<<endl;
                    printInfoF(LF);
                    cout<<"= 0. Back                     ="<<endl;
                    cout<<"= Hapus Film : ";
                    cin.getline(cari,50);
                    Keluar = cari;
                    if (Keluar != "0" && Keluar != ""){
                        if (findElmF(LF,cari)== nil){
                            cout<<" Film "<<cari<<" Belum Tersedia"<<endl;
                        }else{
                            DeleteRF(LR,LF,cari);
                            deleteF(LF,cari);
                            cout<<" Film "<<cari<<" Berhasil Dihapus"<<endl;
                        }
                        cout<<" Press Any Key To Continue ";
                        getch();
                    }
                }
                break;
            case '3':
                 {
                    while (Keluar != "0"){
                        system("cls");
                        cout<<"==============================="<<endl;
                        cout<<"=         Hapus Relasi        ="<<endl;
                        cout<<"==============================="<<endl;
                        printInfoA(LA);
                        cout<<"= 0. Back                     ="<<endl;
                        cout<<"= Hapus Relasi : ";
                        cin.getline(cari,50);
                        Keluar = cari;
                        if (Keluar!="0" && Keluar!=""){
                            if (findElmA(LA, cari)==nil){
                                cout<<" Aktor/Aktris "<<cari<<" Belum Tersedia"<<endl;
                            }
                            else{
                                printInfoAktorR(LR, cari);
                                string del;
                                cout<<endl;
                                cout<<"Pilih Film yang ingin dihapus : ";
                                cin>>del;
                                addressR R =  findElmR(LR,findElmA(LA,cari),findElmF(LF,del));
                                deleteR(LR,R);
                                cout<<"Film "<<del<<" berhasil dihapus dari dari Aktor/Aktris "<<cari<<endl;
                            }
                            cout<<" Press Any Key To Continue ";
                            getch();
                        }
                    }
                }
                break;
            case '0':
                E = 'E';
                break;
        }
    }
}

void menuView(ListA LA, ListR LR, ListF LF){
    char E = 'A';
    addressA A, popA, nonA;
    addressF F;
    addressR R;
    int npop, n, nnon;
    while (E != '0' ){
        char cari[50];
        string Keluar="A";
        system("cls");
        cout<<"=============================="<<endl;
        cout<<"=         Menu View          ="<<endl;
        cout<<"=============================="<<endl;
        cout<<"= 1. Data Aktor/Aktris       ="<<endl;
        cout<<"= 2. Data Film               ="<<endl;
        cout<<"= 3. Aktor/Aktris Top        ="<<endl;
        cout<<"= 4. Seluruh Data            ="<<endl;
        cout<<"=----------------------------="<<endl;
        cout<<"= 0. Back                    ="<<endl;
        cout<<"=============================="<<endl;
        cout<<"= Pilihan :                  ="<<endl;
        cout<<"=============================="<<endl;
        gotoxy(12,10);
        E = getch();
        switch (E){
            case '1':
                while (Keluar != "0"){
                    system("cls");
                    cout<<"==============================="<<endl;
                    cout<<"=        Aktor/Aktris         ="<<endl;
                    cout<<"==============================="<<endl;
                    printInfoA(LA);
                    cout<<"= 0. Back                     ="<<endl;
                    cout<<"\n Lihat Film yang Diperankan Aktor/Aktris: ";
                    cin.getline(cari,50);
                    Keluar = cari;
                    if (Keluar!="0" && Keluar!=""){
                        if(findElmA(LA,cari)==nil){
                            cout<<" Aktor/Aktris "<<cari<<" Belum Tersedia"<<endl;
                        }else{
                            printInfoAktorR(LR, cari);
                        }
                        cout<<" Press Any Key To Continue ";
                        getch();
                    }
                }
                break;
            case '2':
                while (Keluar != "0"){
                    system("cls");
                    cout<<"==============================="<<endl;
                    cout<<"=            Film             ="<<endl;
                    cout<<"==============================="<<endl;
                    printInfoF(LF);
                    cout<<"= 0. Back                     ="<<endl;
                    cout<<"\n Lihat Aktor/Aktris yang Bermain di Film: ";
                    cin.getline(cari,50);
                    Keluar = cari;
                    if (Keluar!="0" && Keluar!=""){
                        if(findElmF(LF,cari)==nil){
                            cout<<" Film "<<cari<<" Belum Tersedia"<<endl;
                        }else{
                            printInfoFilmR(LR, cari);
                        }
                        cout<<" Press Any Key To Continue ";
                        getch();
                    }
                }
                break;
            case '3':
                system("cls");
                cout<<"==============================="<<endl;//ed
                cout<<"=      Aktor/Aktris Top       ="<<endl;
                cout<<"==============================="<<endl;
                A = firstA(LA);
                npop = 0; nnon = 999;
                popA, nonA = A;
                do{
                    R = firstR(LR);
                    n = 0;
                    while(R!=nil){
                        if(aktor(R)==A){
                            n++;
                        }
                        R = nextR(R);
                    }
                    if(n>=npop){
                        popA = A;
                        npop = n;
                    }
                    if(n<=nnon){
                        nonA = A;
                        nnon = n;
                    }
                    A = nextA(A);
                }while(A!=nil);
                cout<<"\n Lihat Aktor/Aktris Yang Paling Top : "<<endl;
                cout<<" "<<infoA(popA)<<" ,Aktor di-"<<npop<<" Film"<<endl;
                cout<<"\n Lihat Aktor/Aktris Yang Paling Tidak Top : "<<endl;
                cout<<" "<<infoA(nonA)<<" ,Aktor di-"<<nnon<<" Film"<<endl;
                cout<<"\n Press Any Key To Continue "<<endl;
                getch();
                break;
            case '4':
                system("cls");
                cout<<"==============================="<<endl;
                cout<<"=        Seluruh Data         ="<<endl;
                cout<<"==============================="<<endl;
                F = firstF(LF);
                do{
                    printInfoFilmR(LR,judul(F));
                    F = nextF(F);
                }while(F!=nil);
                cout<<"= 0. Back                     ="<<endl;
                cout<<"\n Press Any Key To Continue "<<endl;
                getch();
                break;
                break;
            case '0':
                E = '0';
                break;
        }
    }
}
