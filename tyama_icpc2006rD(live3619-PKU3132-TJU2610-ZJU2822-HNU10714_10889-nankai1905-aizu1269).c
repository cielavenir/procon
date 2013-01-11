#include <stdio.h>

char t[1121];
int p[187]; /*187 primes*/
int s[15][1121];

void createtable(){
  int i=2,j;
  for(;i<=1120;i++)
    if(!t[i])
      for(j=i*2;j<=1120;j+=i)
        t[j]=1;
  for(i=2,j=0;i<=1120;i++)
    if(!t[i])p[j++]=i;
}

void createsum(){
  /* http://inazz.jp/pku/3132/ */
  int i=0,k,n;
  s[0][0]=1;
  for(;i<187;i++)
    for(k=14;k;k--)
      for(n=p[i];n<1121;n++)
        s[k][n]+=s[k-1][n-p[i]];
}

int main(){
  int n,k;
  createtable();
  createsum();
  while(scanf("%d%d",&n,&k)&&n)printf("%d\n",s[k][n]);
  return 0;
}