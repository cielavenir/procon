char m[14][14];

solve(i,j){
  m[i][j]='0';
  if(m[i][j-1]-'0')solve(i,j-1);
  if(m[i-1][j]-'0')solve(i-1,j);
  if(m[i+1][j]-'0')solve(i+1,j);
  if(m[i][j+1]-'0')solve(i,j+1);
}

main(){
  int w=12,h=12,i,j,r;
  for(;;printf("%d\n",r)){
    memset(m,'0',sizeof(m));
    r=0;
    for(i=1;i<=h;m[i][13]='0',i++)
      if(scanf("%s",m[i]+1)==-1)return 0;
    for(i=1;i<=h;i++)
      for(j=1;j<=w;j++)
        if(m[i][j]-'0')solve(i,j),r++;
  }
}