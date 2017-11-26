#include "actor.h"

void createListA(ListA &L){
    firstA(L) = nil;
    lastA(L) = nil;
}
addressA alokasiA(string x){
    addressA P = new elmA;
    infoA(P) = x;
    nextA(P) = nil;
    prevA(P) = nil;
    return P;
}
void infiA(ListA &L, addressA P){
    if(firstA(L)==nil){
        firstA(L) = P;
        lastA(L) = P;
    }else{
        nextA(P) = firstA(L);
        prevA(firstA(L)) = P;
        firstA(L) = P;
    }

}
void inlaA(ListA &L, addressA P){
    if(firstA(L)==nil){
        infiA(L,P);
    }else{
        prevA(P) = lastA(L);
        nextA(lastA(L)) = P;
        lastA(L) = P;
    }
}
void inafA(ListA &L, addressA prec, addressA P){
    prevA(nextA(prec)) = P;
    nextA(P) = nextA(prec);
    prevA(P) = prec;
    nextA(prec) = P;
}
void delfiA(ListA &L, addressA &P){
    if(firstA(L)!=nil && lastA(L)!=nil){
        P = firstA(L);
        if(firstA(L)==lastA(L)){
            firstA(L) = nil;
            lastA(L) = nil;
        }else{
            firstA(L) = nextA(P);
            prevA(nextA(P)) = nil;
            nextA(P) = nil;
        }
    }
}
void dellaA(ListA &L, addressA &P){
    if(firstA(L)!=nil && lastA(L)!=nil){
        P = lastA(L);
        if(firstA(L)==lastA(L)){
            delfiA(L,P);
        }else{
            lastA(L) = prevA(P);
            nextA(prevA(P)) = nil;
            prevA(P) = nil;
        }
    }
}
void delafA(ListA &L, addressA prec, addressA &P){
    P = nextA(prec);
    nextA(prec) = nextA(P);
    prevA(nextA(prec)) = prec;
    nextA(P) = nil;
    prevA(P) = nil;
}
void inAscA(ListA &L, addressA P){
    if(firstA(L)==nil){
        lastA(L) = P;
        firstA(L) = P;
    }else{
        addressA Q = firstA(L);
        while(nextA(Q)!=nil && infoA(nextA(Q))<infoA(P)){
            Q = nextA(Q);
        }
        if(infoA(P)<infoA(firstA(L))){
            infiA(L,P);
        }else if(infoA(P)>infoA(lastA(L))){
            inlaA(L,P);
        }else{
            inafA(L,Q,P);
        }
    }
}
void deleteA(ListA &L, string x){
    addressA prec, P;
    P = findElmA(L,x);

    if(firstA(L)==nil){
        cout<<" "<<endl;
    }else if(firstA(L)==lastA(L)){
        P = firstA(L);
        firstA(L) = nil;
        lastA(L) = nil;
    }else{
        if(P==nil){
            cout<<" "<<endl;
        }else{
            if(P==firstA(L)){
                delfiA(L,P);
            }else if(P==lastA(L)){
                dellaA(L,P);
            }else{
                addressA prec = prevA(P);
                delafA(L,prec,P);
            }
        }
    }
}
addressA findElmA(ListA L, string x){
    addressA P = nil;
    P = firstA(L);
    while(P!=nil && infoA(P)!=x) {
        P = nextA(P);
    }
    return P;
}
void printInfoA(ListA L){
    if (firstA(L)==nil){
        cout<<"No List"<<endl;
    }else{
         addressA P = firstA(L);
         int n = 1;
         cout<<"Daftar Aktor: "<<endl;
         while(P!=nil){
            cout<<n<<". "<<infoA(P)<<endl;
            n += 1;
            P=nextA(P);
         }
         cout<<endl;
    }
}
