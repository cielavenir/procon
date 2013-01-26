#include <stdio.h>

//50000 for aizu0056
//1000000 for aizu0185
#define IN_MAX 32768

char table[IN_MAX+1];

void createtable1(){ //0->prime 1->not prime
  int i=2,j;
  table[1]=1;
  for(;i<=IN_MAX;i++)
    if(!table[i])
      for(j=i*2;j<=IN_MAX;j+=i)
        table[j]=1;
}

void put(int n){
  int i=2,s=0;
  for(;i<=n/2;i++){
    if(table[i])continue;
    if(!table[n-i]){
      s++;
    }
  }
  printf("%d\n",s);
}

int main(){
  int n;
  createtable1();
  while(1){
    scanf("%d",&n);
    if(!n)return 0;
    put(n);
  }
}