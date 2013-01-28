#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int lcs[5999][5999];
char a[5999],b[5999];
main(){
  int i,j,_a,_b;
  scanf("%s%s",a+1,b+1);
    _a=strlen(a+1);_b=strlen(b+1);
    for(i=1;i<=_a;i++)
      for(j=1;j<=_b;j++)
        lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
    printf("%d\n",_a+_b-2*lcs[_a][_b]);
}