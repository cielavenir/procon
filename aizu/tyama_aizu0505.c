int a[100];
main(i,j,m,n){
  for(;~scanf("%d%d",&n,&m)&&n;){
    for(i=0;i<m;i++)a[i]=i+1;
    for(;n;n--)
      for(i=0;i<m;i++)
        scanf("%d",&j),a[i]+=j*10000;
    for(i=0;i<m-1;i++)
      for(j=0;j<m-1;j++)
        if(a[j]/10000<a[j+1]/10000)
          n=a[j],a[j]=a[j+1],a[j+1]=n;
    for(i=0;i<m;i++)
      printf("%d%c",a[i]%10000,i==m-1?'\n':' ');
  }
  return 0;
}
