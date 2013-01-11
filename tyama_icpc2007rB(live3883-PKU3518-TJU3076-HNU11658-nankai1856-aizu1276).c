#include <stdio.h>

#define IN_MAX 1299709

char table[IN_MAX+1];

void createtable1(){ //0->prime 1->not prime
  int i=2,j;
  for(;i<=IN_MAX;i++)
    if(!table[i])
      for(j=i*2;j<=IN_MAX;j+=i)
        table[j]=1;
}

void createtable2(){
  int i=2,j=2,x;
  for(;i<=IN_MAX;i++)
    if(!table[i]){
      for(x=j+1;x<i;x++)
        table[x]=i-j;
      j=i;
    }
}

int main(){
  int i;
  createtable1();
  createtable2();
  while(scanf("%d",&i)&&i)printf("%d\n",table[i]);
  return 0;
}