int x[9999],d[9999];

int lis(n){
  int i,j,I;
  for(i=-1;I=0,i++<n;d[i]=I+1)
    for(j=i-1;~j;j--)
      if(x[j]>x[i]&&I<d[j])I=d[j];
  for(i=j=0;i<n;i++)
    if(d[i]>d[j])j=i;
  return d[j];
}

main(c,n){
  for(;n;){
    for(n=0;d[n]=0,scanf("%d",x+n);n++)
      if(x[n]==-1)break;
    if(n)printf("Test #%d:\n  maximum possible interceptions: %d\n\n",c++,lis(n));
  }
}