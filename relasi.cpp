#include "relasi.h"

void createListR(ListR &L){
    firstR(L) = nil;
}
void infiR(ListR &L, addressR P){
    nextR(P) = firstR(L);
    firstR(L) = P;
}
void inlaR(ListR &L, addressR P){
    if(firstR(L)==nil){
        infiR(L,P);
    }else{
        addressR Q = firstR(L);
        while(nextR(Q)!=nil){
            Q = nextR(Q);
        }
        nextR(Q) = P;
    }
}
void inafR(ListR &L, addressR prec, addressR P){
    nextR(P) = nextR(prec);
    nextR(prec) = P;
}
void delfiR(ListR &L, addressR &P){
    if(firstR(L)!=nil){
        P = firstR(L);
        firstR(L) = nextR(P);
        nextR(P) = nil;
    }
}
void dellaR(ListR &L, addressR &P){
    if(firstR(L)!=nil){
        P = firstR(L);
        if(nextR(P)==nil){
            delfiR(L,P);
        }else{
            while(nextR(nextR(P))!=nil){
                P = nextR(P);
            }
            addressR Q = P;
            P = nextR(P);
            nextR(Q) = nil;
        }
    }
}
void delafR(ListR &L, addressR prec, addressR &P){
    P = nextR(prec);
    nextR(prec) = nextR(P);
    nextR(P) = nil;
}
void deleteR(ListR &L, addressR &P){
    addressR prec;
    if(firstR(L)==nil){
        cout<<" "<<endl;
    }else{
        if(firstR(L)==P){
            delfiR(L,P);
        }else if(nextR(P)==nil){
            dellaR(L,P);
        }else{
            addressR prec = firstR(L);
            while(nextR(prec)!=P){
                prec = nextR(prec);
            }
            delafR(L,prec,P);
        }
    }
}

addressR alokasiR(addressA A, addressF F){
    addressR Q = new elmR;
    aktor(Q) = A;
    film(Q) = F;
    nextR(Q) = nil;
    return Q;
}
addressR findElmR(ListR L, addressA A, addressF F){
    addressR Q = firstR(L);
    while(Q != nil){
        if(aktor(Q)==A && film(Q)==F){
            return Q;
        }
        Q = nextR(Q);
    }
    return nil;
}
void printInfoAktorR(ListR L, string A){
    cout<<"Film yang dibintangi "<<A<<":"<<endl;
    addressR P = firstR(L);
    int n = 1;
    while(P!=nil){
        if(infoA(aktor(P))==A){
            cout<<n<<". "<<judul(film(P))<<", year: "<<year(film(P))<<", duration: "<<duration(film(P))<<" minutes"<<endl;
            n += 1;
        }
        P = nextR(P);
    }
}
void printInfoFilmR(ListR L, string F){
    cout<<"Film "<<F<<" dibintangi oleh:"<<endl;
    addressR P = firstR(L);
    int n = 1;
    while(P!=nil){
        if(infoF(film(P)).judul==F){
            cout<<n<<". "<<infoA(aktor(P))<<endl;
            n += 1;
        }
        P = nextR(P);
    }
}
