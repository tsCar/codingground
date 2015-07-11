#include <iostream>
#include <cmath>
using namespace std;

int ubaciZnamenku(int znamenka, int pozicijaOdKraja, int broj){
    if (pozicijaOdKraja<0||pozicijaOdKraja>9){
        cout<<"\nvrijednost nije (jedna) znamenka";return -1;
    }
    int temp=broj,c=0;
    while (temp%10>0){
        temp/=10;c++;
    }
    if(pozicijaOdKraja>c){
        cout<<"\nBroj ima "<<c<<" znamenaka, umetanje na poziciju "<<pozicijaOdKraja<<" nije moguće.";return -1;
    }
    
    temp=(broj%(int)(pow(10,pozicijaOdKraja)));
    broj/=(int)pow(10,pozicijaOdKraja);
    broj*=10;
    broj+=znamenka;
    broj*=(int)pow(10,pozicijaOdKraja);
    broj+=temp;
    return broj;
}

int main()
{
    for(int i=0;i<10;i++){
        cout<<ubaciZnamenku(3,i,1245678)<<endl;
    }
    cout<<ubaciZnamenku(3,12,22222);
    cout<<ubaciZnamenku(3,-6,22222);
   return 0;
}

