#include <stdio.h>

#define IN_MAX 1000000

char table[IN_MAX+1];

void createtable1(){ //0->prime 1->not prime
  int i=2,j;
  for(;i<=IN_MAX;i++)
    if(!table[i])
      for(j=i*2;j<=IN_MAX;j+=i)
        table[j]=1;
}

void put(int n){ //assert(n<5)
  int i=3;
  for(;i<=n/2;i++){
    if(table[i])continue;
    if(!table[n-i]){
      printf("%d = %d + %d\n",n,i,n-i);
      return;
    }
  }
  printf("Goldbach's conjecture is wrong.\n");
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