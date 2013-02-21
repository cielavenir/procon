int x[9999],d[9999];

int lis(n){
  int i,j,I;
  for(i=-1;I=0,i++<n;d[i]=I+1)
    for(j=i-1;~j;j--)
      if(x[j]<x[i]&&I<d[j])I=d[j];
  for(i=j=0;i<n;i++)
    if(d[i]>d[j])j=i;
  return d[j];
}

i;main(n){
  for(scanf("%d",&n);i<n;i++)scanf("%d",x+i);
  printf("%d\n",lis(n));
exit(0);}