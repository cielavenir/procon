#include <stdio.h>
#include <string.h>

int dp[500][500];
char s[999],*t;
int x;
solve(char *s,char *t){
  int i,j;
  for(i=1;i<strlen(t);i++)
    for(j=1;j<strlen(s);j++)
      dp[i][j]=(t[i]==s[j]?dp[i-1][j]:0)+dp[i][j-1];
/*
  for(i=0;i<strlen(t);i++,puts(""))
    for(j=0;j<strlen(s);j++)
      printf("%02d ",dp[i][j]);
*/
  printf("%d\n",dp[strlen(t)-1][strlen(s)-1]/x);
}

main(int argc, char **argv){
  if(argc>1)freopen(argv[1],"rb",stdin);
  int i,j,c;
  for(;~scanf("%s",s);){
    strtok(s,","),t=strtok(NULL,",");
    memset(dp,0,sizeof(dp));
    for(i=j=0;i<strlen(s);i++){
      if(s[i]==t[0])j++;
      dp[0][i]=j;
    }
    for(c=t[0],x=i=1,j=1;j<strlen(t);j++)
      if(c==t[j])i++;
      else c=t[j],x*=i,i=1;
    solve(s,t);
  }
}