char m[14][14];

solve(i,j){
  m[i][j]='0';
  if(m[i][j-1]-'0')solve(i,j-1);
  if(m[i][j-2]-'0')solve(i,j-2);
  if(m[i][j-3]-'0')solve(i,j-3);
  if(m[i-1][j]-'0')solve(i-1,j);
  if(m[i-2][j]-'0')solve(i-2,j);
  if(m[i-3][j]-'0')solve(i-3,j);
  if(m[i+1][j]-'0')solve(i+1,j);
  if(m[i+2][j]-'0')solve(i+2,j);
  if(m[i+3][j]-'0')solve(i+3,j);
  if(m[i][j+1]-'0')solve(i,j+1);
  if(m[i][j+2]-'0')solve(i,j+2);
  if(m[i][j+3]-'0')solve(i,j+3);
}

main(c){
  int n,h=10,i,j;
  for(scanf("%d",&n);c<=n;c++){
    printf("Data %d:\n",c);
    memset(m,'0',sizeof(m));
    for(i=3;i<=h;m[i][11]='0',i++)
      scanf("%s",m[i]+3);
    scanf("%d%d",&i,&j);
    solve(j+2,i+2);
    for(i=3;i<=h;printf("%s\n",m[i]+3),i++)
      m[i][11]=0;
  }
  return 0;
}