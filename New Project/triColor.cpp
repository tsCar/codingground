#include <iostream>
#include <string>
using namespace std;

string solution(int a[], int n);
string rekurzija(int a[],int indeks,int rgb[], string raspored, int n, string *dobarRaspored);

int main()
{
   int a[]={3,7,2,5,4};
   cout<<endl<<endl<<solution(a,5)<<endl<<endl;
   
   return 0;
}

string solution(int a[], int n){
    string *dobarRaspored=new string;
    *dobarRaspored="impossible";
    int rgb[3]={0};
    int indeks;
    rekurzija(a,0,rgb,"",n,dobarRaspored);
    return *dobarRaspored;
}

string rekurzija(int a[],int indeks,int rgb[], string raspored, int n, string *dobarRaspored){
    if(indeks<n){
        for (int i=0;i<3;i++){
        rgb[i]+=a[indeks];
        switch(i){
            case 0:
                raspored.push_back('r');
                rekurzija(a,indeks+1,rgb,raspored,n,dobarRaspored);
                break;
            case 1:
                raspored.push_back('g');
                rekurzija(a,indeks+1,rgb,raspored,n,dobarRaspored);
                break;
            case 2:
                raspored.push_back('b');
                rekurzija(a,indeks+1,rgb,raspored,n,dobarRaspored);
                break;
            }
            raspored.resize(raspored.size()-1);
        }
        if(indeks==n&&rgb[0]==rgb[1]&&rgb[0]==rgb[2]){
          *dobarRaspored=raspored;
        }
    }
    return raspored;
}