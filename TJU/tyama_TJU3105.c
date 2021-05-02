#include <stdio.h>
#define IN_MAX 999999
char table[IN_MAX+1];
int x[99999];

void createtable(){
  int i=2,j;
  for(;i<=IN_MAX;i++)
    if(!table[i])
      for(j=i*2;j<=IN_MAX;j+=i)
        table[j]=1;
}

int main(){
  int i,*p=x;
  createtable();
  for(i=2;i<IN_MAX;i++)
    if(!table[i])
      *p=i,p++;
  for(scanf("%s",&i);~scanf("%d",&i);printf("%d\n",x[i-1]));
  return 0;
}