int m[51][51],M[51][51];
main(h,w,i,j){
  for(scanf("%d%d",&h,&w),getchar(),i=1;i<=h;getchar(),i++)
    for(j=1;j<=w;j++)
      m[i][j]=getchar()-'0';
  for(i=1;i<=h;i++)M[i][1]=m[i][1]+=m[i-1][1];
  for(j=1;j<=w;j++)M[1][j]=m[1][j]+=m[1][j-1];
  for(i=2;i<=h;i++)
    for(j=2;j<=w;j++)
      M[i][j]=m[i][j]+(M[i-1][j]<M[i][j-1]?M[i-1][j]:M[i][j-1]);
  printf("%d\n",M[h][w]);
  exit(0);
}