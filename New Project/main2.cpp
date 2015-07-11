#include <iostream>
#include <cmath>
using namespace std;

int prebrojZnamenke(int broj){
    int c=0;
    while (broj%10>0){
        broj/=10;
        c++;
    }
    return c;
}
int ubaciZnamenku(int znamenka, int pozicijaOdKraja, int broj){
    int c=prebrojZnamenke(broj);
    if(znamenka>=0&&znamenka<=9&&pozicijaOdKraja<=c&&pozicijaOdKraja>=0){
       int duljina=(int)(pow(10,pozicijaOdKraja));
       int temp=broj%duljina;
       broj/=duljina;
        broj*=10;
        broj+=znamenka;
        broj*=duljina;
       broj+=temp;
        
    }
    return broj;
}


int main()
{//umeće znamenke da jednakost vrijedi
   int prvi,drugi,rez;
   cout<<"prvi+drugi=rez\n";
   cout<<"\nprvi pribrojnik: "; cin>>prvi;
   cout<<"\ndrugi pribrojnik: "; cin>>drugi;
   cout<<"\nrezultat: "; cin>>rez;
   
   int znamenakaUprvom=prebrojZnamenke(prvi);
   int znamenakaUdrugom=prebrojZnamenke(drugi);
   int znamenakaUrezultatu=prebrojZnamenke(rez);
   cout<<znamenakaUprvom<<endl;
   for(int i=-1;i<=znamenakaUprvom;i++){prvi=ubaciZnamenku(6,i,prvi);cout<<prvi<<endl;}
   cout<<"end test";
   for(int i=-1;i<znamenakaUprvom;i++){
       for(int j=0;j<10;j++){
           prvi=ubaciZnamenku(j,i,prvi);
           for (int k=-1;k<znamenakaUdrugom;k++){
                for(int l=0;l<10;l++){
                    drugi=ubaciZnamenku(k,l,drugi);
                    for (int m=-1;m<znamenakaUdrugom;m++){
                         for(int n=0;n<10;n++){
                            rez=ubaciZnamenku(m,n,rez);
                            if(prvi+drugi==rez){
                                cout<<prvi<<" + "<<drugi<<" = "<<rez<<endl;
                            }
                         }
                        }
                   }
                }
           }
       }
       return 0;
}

