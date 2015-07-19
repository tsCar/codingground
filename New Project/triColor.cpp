#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a[], int n, vector<string> *sviRasporedi);
string rekurzija(int a[],int indeks,int rgb[], string raspored, int n, string *dobarRaspored, vector<string> *sviRasporedi);

int main()
{
    vector<string> *sviRasporedi=new vector<string>;
   int a[]={3,7,2,5,4};
   cout<<endl<<endl<<solution(a,5,sviRasporedi)<<endl<<endl;
  // for(std::vector<string>::iterator it=(*sviRasporedi).begin();it!=(*sviRasporedi).end();it++)cout<<(*sviRasporedi).at(it)<<endl;
   for(int i=0;i<(*sviRasporedi).size();i++)cout<<(*sviRasporedi).at(i)<<endl;
   return 0;
}

string solution(int a[], int n,vector<string> *sviRasporedi){// svi rasporedi su dodani da mogu pokupit sve rezultate
//funkcija radi i kad se oni izbace(potpis ostane kakav je zadan)
    
    string *dobarRaspored=new string;
    *dobarRaspored="impossible";
    int rgb[3]={0};
    int indeks;
    rekurzija(a,0,rgb,"",n,dobarRaspored,sviRasporedi);
    return *dobarRaspored;
}

string rekurzija(int a[],int indeks,int rgb[], string raspored, int n, string *dobarRaspored,vector<string> *sviRasporedi){
    
    if(indeks<n){
        for (int i=0;i<3;i++){
        rgb[i]+=a[indeks];
        switch(i){
            case 0:
                raspored.push_back('r');
                break;
            case 1:
                raspored.push_back('g');
                break;
            case 2:
                raspored.push_back('b');
                break;
            }
         //   if(raspored.size()==n){for(int t=0;t<3;t++)cout<<"rgb["<<t<<"]"<<": "<<rgb[t]<<" "<<raspored<<" ";}
            rekurzija(a,indeks+1,rgb,raspored,n,dobarRaspored,sviRasporedi);
            raspored.resize(raspored.size()-1);
            rgb[i]-=a[indeks];
            cout<<endl;
        }
    }
        if(indeks==n&&rgb[0]==rgb[1]&&rgb[0]==rgb[2]){
          *dobarRaspored=raspored;
          (*sviRasporedi).push_back(raspored);
        }
   
    return raspored;
}

