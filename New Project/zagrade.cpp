#include <iostream>
#include <string>
using namespace std;
#include <vector>

int main()
{
   vector<char> stog;
   string input;
   bool ispravno=true;
   getline(cin,input);
   input="{([])({[]}fg)}";cout<<"input length "<<input.length();
   for (int i=0;i<input.length();i++){
       if(input.at(i)=='{'||input.at(i)=='['||input.at(i)=='(') stog.push_back(input.at(i));
       else if(input.at(i)=='}'||input.at(i)==']'||input.at(i)==')') {
           if(stog.size()==0){
               cout<<"NE!";
               ispravno=false;
           }
           else {
               cout<<"input i:  "<<input.at(i)<<", stog back: "<<stog.back()<<endl;
               switch(stog.back()){
                   case '(':
                    if(input.at(i)!=')')ispravno=false;
                    break;
                   case '[':
                    if(input.at(i)!=']')ispravno=false;
                    break;
                   case '{':
                    if(input.at(i)!='}')ispravno=false;
                    break;
               }
               stog.pop_back();
           }
       }
   }
   if(stog.size()!=0)ispravno=false;
   if(ispravno)cout<<"yay\n";else cout<<"boo\n";
   return 0;
}