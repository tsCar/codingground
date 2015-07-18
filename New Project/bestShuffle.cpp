#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;


int findShuffle(int*);
int** napraviPoljePermutacija(int,int *);
void permutiraj(int**,int*,int, int,int&);
void zamijeni(int&, int&);
int main(){
    int s[4]={5,3,-1,5} ;
    cout<<endl<<findShuffle(s)<<endl<<endl;   
}

int findShuffle(int *s){
    
    int **permutacije = napraviPoljePermutacija(4,s);
    int max=0,sad;
    for (int i=0;i<24;i++){
        for (int j=0;j<4;j++)cout<<permutacije[i][j]<<" ";
        cout<<endl;
        sad=abs(permutacije[i][0]-permutacije[i][1]) + abs(permutacije[i][1]-permutacije[i][2]) + abs(permutacije[i][2]-permutacije[i][3]) ;
        if (max<sad)max=sad;
    }
    return max;
}

int** napraviPoljePermutacija(int size,int *s){ //nisam morao proslijedit size jer mi je potpis funkcije findshuffle zadan pa će size dalje uvijek bit 4 ali kad već radim funkciju, nek bude robusna...
    int brojPermutacija=1,counter=0;
    for(int i=2;i<=size;i++)brojPermutacija*=i;
    int **permutacije=new int*[brojPermutacija];
    for(int i=0;i<brojPermutacija;i++) permutacije[i]=new int[size];
    permutiraj(permutacije,s,size-1,size,counter);
     for(int i=0;i<brojPermutacija;i++) {for(int j=0;j<4;j++)cout<<permutacije[i][j]<<" ";cout<<endl;}
    return permutacije;
}
void permutiraj(int **permutacije,int *s,int pozicija,int velicina, int &counter){
    if(pozicija==0) {
        for(int i=0;i<velicina;i++)permutacije[counter][i]=s[i];
        counter++;
    }
    else {
        for(int i=(pozicija);i>=0;i--){
            zamijeni(s[pozicija],s[i]);
            permutiraj(permutacije,s,(pozicija-1),velicina,counter);
            zamijeni(s[pozicija],s[i]);
        }
    }
    return;
    
}
void zamijeni(int &a, int &b){
    int tmp=a;
    a=b;b=tmp;
}


