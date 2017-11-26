#include "film.h"

void createListF(ListF &L){
    firstF(L) = nil;
}
addressF alokasiF(infoF x){
    addressF P;
    P = new elmF;
    infoF(P) = x;
    nextF(P) = nil;
    return P;
}
void dealokasi(addressF &P){
    delete P;
}
void infiF(ListF &L, addressF P){
    nextF(P) = firstF(L);
    firstF(L) = P;
}
void inlaF(ListF &L, addressF P){
    if(firstF(L)==nil){
        infiF(L,P);
    }else{
        addressF Q = firstF(L);
        while(nextF(Q)!=nil){
            Q = nextF(Q);
        }
        nextF(Q) = P;
    }
}
void inafF(ListF &L, addressF P, addressF Prec){
    nextF(P) = nextF(Prec);
    nextF(Prec) = P;
}
addressF findElmF(ListF L, string judul){
    addressF P;
    P = firstF(L);
    while(P!=nil && judul(P)!=judul){
        if (judul(P) == judul){
            return P;
        }
        P = nextF(P);
    }
    return P;
}
void delfiF(ListF &L, addressF &P){
    if(firstF(L)!=nil){
        P = firstF(L);
        firstF(L) = nextF(P);
        nextF(P) = nil;
    }else {
        cout<<"Listnya Kosong"<<endl;
    }
}
void dellaF(ListF &L, addressF &P){
    if(firstF(L)!=nil){
        P = firstF(L);
        if(nextF(P)==nil){
            delfiF(L,P);
        }else{
            while(nextF(nextF(P))!=nil){
                P = nextF(P);
            }
            addressF Q = P;
            P = nextF(Q);
            nextF(Q) = nil;
        }
    }
}
void delafF(ListF &L, addressF prec, addressF &P){
    P = nextF(prec);
    nextF(prec) = nextF(P);
    nextF(P) = nil;
}
void deleteF(ListF &L, string judul){
    addressF prec, P;
    P = findElmF(L,judul);
    if(firstF(L)==nil){
        cout<<" "<<endl;
    }else{
        if(firstF(L)==P){
            delfiF(L,P);
        }else if(nextF(P)==nil){
            dellaF(L,P);
        }else{
            addressF prec = firstF(L);
            while(nextF(prec)!=P){
                prec = nextF(prec);
            }
            delafF(L,prec,P);
        }
    }
}
void printInfoF(ListF L){
    if(firstF(L)==nil){
        cout<<"No List"<<endl;
    }else{
        addressF P = firstF(L);
        int n = 1;
        cout<<"Daftar Film: "<<endl;
        while(P!=nil){
            cout<<n<<". "<<judul(P)<<", year: "<<year(P)<<", duration: "<<duration(P)<<" minutes"<<endl;
            n += 1;
            P = nextF(P);
        }
        cout << endl;
    }
}
