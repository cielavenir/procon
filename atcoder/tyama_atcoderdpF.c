#define M 3009
#include <stdio.h>
char* F(char *b,int n,FILE *f){char *r=fgets(b,n,f);if(!r)return NULL;b[strlen(b)-1]=0;return r;}
#define max(a,b) ((a)>(b)?(a):(b))
int lcs[M][M];
char a[M],b[M],l[M];
backtrack(i,j){
	if(i==0||j==0);
	else if(a[i]==b[j])backtrack(i-1,j-1),putchar(a[i]);
	else if(lcs[i][j-1]>lcs[i-1][j])backtrack(i,j-1);
	else backtrack(i-1,j);
}
main(int argc, char **argv){
  if(argc>1)freopen(argv[1],"rb",stdin);
  int i,j,_a,_b;
  strcpy(a,"*"),strcpy(b,"*");
  F(l,M,stdin);strcat(a,l);
  F(l,M,stdin);strcat(b,l);
  _a=strlen(a+1);_b=strlen(b+1);
  for(i=1;i<=_a;i++)
    for(j=1;j<=_b;j++){
#if 1
      // https://qiita.com/drken/items/a5e6fe22863b7992efdb#%E5%95%8F%E9%A1%8C-8%E6%9C%80%E9%95%B7%E5%85%B1%E9%80%9A%E9%83%A8%E5%88%86%E5%88%97-lcs-%E5%95%8F%E9%A1%8C
      if(a[i]==b[j])lcs[i][j]=lcs[i-1][j-1]+1;
      else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
#else
      lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
#endif
    }
  backtrack(_a,_b);puts("");
}
