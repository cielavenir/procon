char m[102][102];

solve(c,i,j){
  m[i][j]=0;
  if(m[i][j-1]==c)solve(c,i,j-1);
  if(m[i-1][j]==c)solve(c,i-1,j);
  if(m[i+1][j]==c)solve(c,i+1,j);
  if(m[i][j+1]==c)solve(c,i,j+1);
}

main(){
  int w,h,i,j,r;
  for(;scanf("%d%d",&h,&w),h;printf("%d\n",r)){
    memset(m,0,sizeof(m));
    for(r=0,i=1;i<=h;i++)scanf("%s",m[i]+1);
    for(i=1;i<=h;i++)for(j=1;j<=w;j++)if(m[i][j])solve(m[i][j],i,j),r++;
  }
exit(0);}