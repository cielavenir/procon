#include <stdio.h>
char* F(char *b,int n,FILE *f){char *r=fgets(b,n,f);if(!r)return NULL;b[strlen(b)-1]=0;return r;}
#define max(a,b) ((a)>(b)?(a):(b))
int lcs[999][999];
char a[999],b[999],l[999];
backtrack(i,j){
	if(i==0||j==0);
	else if(a[i]==b[j])backtrack(i-1,j-1),putchar(a[i]);
	else if(lcs[i][j-1]>lcs[i-1][j])backtrack(i,j-1);
	else backtrack(i-1,j);
}
main(int argc, char **argv){
  if(argc>1)freopen(argv[1],"rb",stdin);
  int i,j,_a,_b;
  strcpy(a,"*"),strcpy(b,"*"),F(l,999,stdin);
  for(;F(l,999,stdin),l[0]!='>';)strcat(a,l);
  for(;F(l,999,stdin);)strcat(b,l);
    _a=strlen(a+1);_b=strlen(b+1);
    for(i=1;i<=_a;i++)
      for(j=1;j<=_b;j++)
        lcs[i][j]=max(max(lcs[i-1][j],lcs[i][j-1]),lcs[i-1][j-1]+(a[i]==b[j]));
    backtrack(_a,_b);puts("");
}