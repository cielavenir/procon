#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int lcs[499][499];
char a[999],*b;
char* F(char *b,int n,FILE *f){char *r=fgets(b,n,f);if(!r)return NULL;b[strlen(b)-1]=0;return r;}
backtrack(i,j){
	if(i==0||j==0);
	else if(a[i]==b[j])backtrack(i-1,j-1),putchar(a[i]);
	else if(lcs[i][j-1]>lcs[i-1][j])backtrack(i,j-1);
	else backtrack(i-1,j);
}
main(int argc, char **argv){
  if(argc>1)freopen(argv[1],"rb",stdin);
  int i,j,_a,_b;
  while(F(a+1,998,stdin)){
    b=strchr(a+1,';');if(!b)continue;*b=0;
    memset(lcs,0,sizeof(lcs));
    _a=strlen(a+1);_b=strlen(b+1);
    for(i=1;i<=_a;i++)
      for(j=1;j<=_b;j++)
        lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
    backtrack(_a,_b);puts("");
  }
}