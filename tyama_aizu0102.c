int m[100][100];
main(n,i,j,s){
  for(;scanf("%d",&n),n;){
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        scanf("%d",m[i]+j);
    for(i=0;i<n;m[i][j]=s,i++)
      for(s=j=0;j<n;j++)s+=m[i][j];
    for(i=0;i<n+1;m[j][i]=s,i++)
      for(s=j=0;j<n;j++)s+=m[j][i];
    for(i=0;i<n+1;puts(""),i++)
      for(s=j=0;j<n+1;j++)printf("%5d",m[i][j]);
  }
  return 0;
}