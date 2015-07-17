#include <iostream>

using namespace std;

const int m=3;
const int n=4;
int racunaj(int[][],int,int);
int rekurzivno(inp polje[][],int m, int n,int px, int py, int potez[]);
int main()
{
   polje[M][N];
   for (int i=0;i<m;i++){
       for (int j=0;j<n;j++){
           polje[i][j]=0;
       }
   }
   polje[2][0]=1;
   polje[1][2]=1;
   
   racunaj(polje,0,0);
   
   
   return 0;
}
int rekurzivno(inp polje[][],int m, int n,int px, int py, int potezi[][]){
    if(px==m&&py==n) return 1;
    inr min=-2,tmpMin;
    else {
        for(int i=0;i<8;i++){
            if(polje[px][py]==1||px>m||py>n)continue;
            else {
                tmpMin=rekurzivno(polje,m,n,(px+potezi[i][0]),(py+potezi[i][1]),potezi);
                polje[px][py]=1;
                if(min<0&&tmpMin>0)min=tmpMin;
                else if (min>tmpMin) min=tmpMin;
            }
        }
        return 1+min;
    }
}
int racunaj(int polje[][],int m,int n){
    int min=-1;
    int potezi[8][2]={{1,2},{2,1},{2,-1},{1,-2},{1-,-2},{-2,-1},{-2,1},{-1,2}};
    min=rekurzivno(polje,m,n,0,0,potezi);
    return min;
}
