#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int lcs[999][999];
int a[999],b[999];
int f;
backtrack(i,j){
	if(i==0||j==0);
	else if(a[i]==b[j])backtrack(i-1,j-1),f=printf(f?" %d":"%d",a[i]);
	else if(lcs[i][j-1]>lcs[i-1][j])backtrack(i,j-1);
	else backtrack(i-1,j);
}
main(){
  int i,j,_a,_b;
  scanf("%d%d",&_a,&_b);
  for(i=1;i<=_a;i++)scanf("%d",a+i);
  for(i=1;i<=_b;i++)scanf("%d",b+i);
  for(i=1;i<=_a;i++)
    for(j=1;j<=_b;j++)
      lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
  backtrack(_a,_b);puts("");
}