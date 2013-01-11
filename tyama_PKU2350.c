int a[1001];
main(c,n,i,x){
  double d;
  for(scanf("%d",&c);c;c--){
    for(d=i=x=0,scanf("%d",&n);i<n;i++)scanf("%d",a+i),d+=a[i];
    d/=n;
    for(i=0;i<n;i++)if(d<a[i])x++;
    printf("%.3f%%\n",(double)100*x/n);
  }
}