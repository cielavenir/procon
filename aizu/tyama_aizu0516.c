int a[100001],b[100001];
main(n,k,m,i){
  for(;~scanf("%d%d",&n,&k)&&n;printf("%d\n",m)){
    for(i=1;i<=k;i++)
      scanf("%d",a+i),b[i]=b[i-1]+a[i];
    for(m=b[i];i<=n;i++){
      scanf("%d",a+i),b[i]=b[i-1]+a[i]-a[i-k];
      if(m<b[i])m=b[i];
    }
  }
  return 0;
}
