//Kljuse kreće sa gornjeg lijevog polja i treba stići na donje desno. 

#include <iostream>

using namespace std;
int level=0;//za debug, pobrisat kasnije
const int M=3;
const int N=4;
int racunaj(int**,int,int);
int rekurzivno(int **,int M, int N,int px, int py, int potezi[][2]);
int main()
{

 int **polje=new int*[N];
 
   for (int i=0;i<N;i++){
       polje[i]=new int[M];
       for (int j=0;j<M;j++){
           polje[i][j]=0;
       }
   }
   polje[2][0]=1; //Neka polja su blokirana
   polje[1][2]=1;  
   
   for (int i=0;i<N;i++){
       for (int j=0;j<M;j++){
           cout<<polje[i][j];
       }cout<<endl;
   }
   cout<<"\n\n\n\n\n\n\n\n\n\n\n";
   cout<<"Minimalan broj poteza je "<<racunaj(polje,N,M)<<endl;
   return 0;
}
int rekurzivno(int **polje,int M, int N,int px, int py, int potezi[][2]){
    cout<<"nova rekurzija ("<<px<<","<<py<<")\n";
    int tmpMin[8],min;
    if(px>=M||py>=N||px<0||py<0) {cout<<"vracam -1 za ("<<px<<","<<py<<") jer je izvan table\n";return -1;}
    if(polje[px][py]==1){
        cout<<"vracam -1 za ("<<px<<","<<py<<") jer je posjeceno\n";
        return -1;
        
    }
    if(px==M-1&&py==N-1){cout<<"vracam 1 za ("<<px<<","<<py<<")\n";return 0;}
    else{
        level++;
        polje[px][py]=1;
        cout<<"level "<<level<<", idem u for\n";
        for(int i=0;i<8;i++){
            
            tmpMin[i]=rekurzivno(polje,M,N,(px+potezi[i][0]),(py+potezi[i][1]),potezi);
            
        }
        if(px!=0||py!=0)polje[px][py]=0;
        cout<<"izasao iz fora \n\n";
        min=tmpMin[0];
        for(int i=1;i<8;i++){
            if((min<0)||(min>=0&&tmpMin[i]>=0&&min>tmpMin[i]))min=tmpMin[i];
        }
        level--;
        cout<<"level "<<level<<endl;
        //Za svako polje funk. "kaže" "udaljenost mene do zadnjeg je min (rezultat rekurzivnih poziva), znači od čvora koji me pozvao je jedan potez više"
        //Kad se pozove sa zadnjim čvorom udaljenost je 0.
        if(min>=0){cout<<"vracam "<<1+min<<"\n";return 1+min;}
        else {cout<<"vracam -1\n";return -1;}
    }
}
int racunaj(int **polje,int M,int N){
    int min;
    int potezi[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    min=rekurzivno(polje,M,N,0,0,potezi);
    cout<<"kad se vrati iz rekurzija min je "<<min<<endl;
    return min;
}
