#include <stdio.h>
#define IN_MAX 999999

char table[IN_MAX+1];

void createtable(){ //0->prime 1->not prime
  int i=2,j;
  table[0]=table[1]=1;
  for(;i<=IN_MAX;i++)
    if(!table[i])
      for(j=i*2;j<=IN_MAX;j+=i)
        table[j]=1;
}

int main(){
  int a,d,n,c,x;
  createtable();
  for(;;){
    c=0;
    scanf("%d%d%d",&a,&d,&n);
    if(a==0)return 0;
    for(x=a;;x+=d){
      if(!table[x])c++;
      if(c==n){
        printf("%d\n",x);
        break;
      }
    }
  }
}