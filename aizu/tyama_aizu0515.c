int z[17][17];
main(a,b,n,i,j){
  for(;scanf("%d%d%d",&a,&b,&n)>2;printf("%d\n",z[a][b])){
    memset(z,0,sizeof(z));
    for(;n;n--)
      scanf("%d%d",&i,&j),z[i][j]=-1;
    z[1][1]=1;
    for(i=1;i<=a;i++)
      for(j=1;j<=b;j++)
        if((i|j)-1&&~z[i][j])
          z[i][j]=(~z[i-1][j]?z[i-1][j]:0)+(~z[i][j-1]?z[i][j-1]:0);
  }
  return 0;
}
