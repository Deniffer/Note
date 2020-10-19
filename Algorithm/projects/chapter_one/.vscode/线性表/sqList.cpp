#include <iostream>
#define MAXSIZE 50
typedef int ElemType;
typedef struct 
{
   ElemType data[MAXSIZE];
   int length;
}sqList;
using namespace std;

void Reverse(sqList &L){
   int temp;
   cout<<"This is what we are:[";
   for (int n=0;n<L.length;n++) cout<<L.data[n]<<",";
   cout<<"]"<<endl;
   for(int i=0;i<L.length/2;i++){
      temp = L.data[i];
      cout<<"temp="<<temp;
      L.data[i] = L.data[L.length-1-i];//L.length-1 means 9  cause the index from 0-9
      L.data[L.length-i-1] =temp;
      cout<<"Now the "<<i<<" Loop=[";
      for (int n=0;n<L.length;n++) cout<<L.data[n]<<",";
      cout<<"]"<<"   ";
      cout<<"the L.length-i is "<<L.data[L.length-i]<<"L.length is "<<L.length<<endl;

   }
}
bool Del_Min_text(sqList &L,ElemType &value){
   if(L.length==0)
      return false;
   value=L.data[0];
   int pos=0;
   for(int i=1;i<L.length;i++){
      if(L.data[i]<value){
         value=L.data[i];
         pos=i;
      }
   }
   L.data[pos]=L.data[L.length-1];
   L.length--;
   return true;
}

void Del_X(sqList &L,ElemType &x){  //       Mythought: use a temp sqList to store the List .Correct Answer: move k pos if value!=x
   int k=0;
   for(int i=0;i<L.length;i++){
      if(L.data[i]!=x){
         L.data[k]=L.data[i];
         k++;
      }
   }
   L.length=k;
}


int main()
{
   sqList L={{1,2,3,4,5,6,7,8,9,10},10};   
   //Reverse(L);
   return 0;
}
