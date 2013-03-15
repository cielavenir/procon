#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

//101 for 1163/HNU10014/atcoderwupc2012A, 351 for 3176, 1001 for XMU1010
#define M 351
int x[M][M];
int s[M][M];

main(int argc,char **argv){
  if(argc>1)freopen(argv[1],"rb",stdin);
  int n,i,j;
  //scanf("%d",&n);
  //n=15; //euler18
  //n=100; //euler67, codeeval89
  for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
      scanf("%d",x[i]+j);
  for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
      s[i][j]=max(s[i-1][j-1]+x[i][j],s[i-1][j]+x[i][j]);
  j=0;
  for(i=1;i<=n;i++)
    j=max(j,s[n][i]);
  printf("%d\n",j);
  exit(0);
}

//bootstrap for HNU10014
//main(n){scanf("%d",&n);for(;n;n--)_main();}