int m[9][9],f[27][9];
int solve(){
  int i,j;
  memset(f,0,sizeof(f));
  for(i=0;i<9;i++)
    for(j=0;j<9;j++)
      f[i][m[i][j]]++,f[9+j][m[i][j]]++,f[18+(i/3)*3+j/3][m[i][j]]++;
  for(i=0;i<27;i++)
    for(j=0;j<9;j++)if(f[i][j]!=1)return 0;
  return 1;
}
main(c,n,i,j){
  scanf("%d",&n);
  for(;c<=n;c++){
    for(i=0;i<9;i++)for(j=0;j<9;j++)scanf("%d",m[i]+j),m[i][j]--;
    printf("Case %d:\n%s!\n",c,solve()?"Yes":"No");
  }
  return 0;
}