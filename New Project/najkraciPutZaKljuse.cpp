#include <iostream>

using namespace std;
int level=0;//za debug, pobrisat kasnije
const int M=4;
const int N=3;
int racunaj(int[][N],int,int);
int rekurzivno(int polje[][N],int M, int N,int px, int py, int potezi[][2]);
int main()
{
   int polje[M][N];
   for (int i=0;i<M;i++){
       for (int j=0;j<N;j++){
           polje[i][j]=0;
       }
   }
   polje[2][0]=1;
   polje[1][2]=1;
   cout<<"\n\n\n\n\n\n\n\n\n\n\n";
   cout<<racunaj(polje,M,N)<<endl;
   return 0;
}
int rekurzivno(int polje[][N],int M, int N,int px, int py, int potezi[][2]){
    cout<<"nova rekurzija ("<<px<<","<<py<<")\n";
    int tmpMin[8],min;
    if(px>=M||py>=N||px<0||py<0) {cout<<"vracam -1 za ("<<px<<","<<py<<") jer je izvan table\n";return -1;}
    if(polje[px][py]==1){cout<<"vracam -1 za ("<<px<<","<<py<<") jer je posjeceno\n";return -1;}
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
int racunaj(int polje[][N],int M,int N){
    int min;
    int potezi[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    min=rekurzivno(polje,M,N,0,0,potezi);
    cout<<"kad se vrati iz rekurzija min je "<<min<<endl;
    return min;
}

