#include <stdio.h>
#include <string.h>

/*not contains successing chars*/
#define S "welcome to code jam"
int dp[19][500]; /*19 === strlen(S)*/
char s[510];

solve(char *s){
  int i,j;
  for(i=1;i<19;i++)
    for(j=1;j<strlen(s);j++)
      dp[i][j]=((S[i]==s[j]?dp[i-1][j]:0)+dp[i][j-1])%10000;
/*
  for(i=0;i<19;i++,puts(""))
    for(j=0;j<strlen(s);j++)
      printf("%02d ",dp[i][j]);
*/
  printf("%04d\n",dp[18][strlen(s)-1]);
}

main(){
  int m=0,n,i,j;
  for(scanf("%d",&n),getchar();m<n;){
    memset(dp,0,sizeof(dp));
    fgets(s,509,stdin);
    s[strlen(s)-1]=0; /*erase LF*/
    printf("Case #%d: ",++m);
    for(i=j=0;i<strlen(s);i++){
      if(s[i]==S[0])j++;
      dp[0][i]=j;
    }
    solve(s);
  }
}