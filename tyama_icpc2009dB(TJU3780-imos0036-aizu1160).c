/*1726-1734*/
int m[52][52];

solve(i,j){
  m[i][j]=0;
  if(m[i-1][j-1])solve(i-1,j-1);
  if(m[i][j-1])solve(i,j-1);
  if(m[i+1][j-1])solve(i+1,j-1);
  if(m[i-1][j])solve(i-1,j);
  if(m[i+1][j])solve(i+1,j);
  if(m[i-1][j+1])solve(i-1,j+1);
  if(m[i][j+1])solve(i,j+1);
  if(m[i+1][j+1])solve(i+1,j+1);
}

main(){
  int w,h,i,j,r;
  for(;scanf("%d%d",&w,&h),w;printf("%d\n",r)){
    memset(m,0,sizeof(m));
    r=0;
    for(i=1;i<=h;i++)
      for(j=1;j<=w;j++)
        scanf("%d",m[i]+j);
    for(i=1;i<=h;i++)
      for(j=1;j<=w;j++)
        if(m[i][j])solve(i,j),r++;
  }
}