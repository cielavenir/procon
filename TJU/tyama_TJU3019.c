main(){
  unsigned long long r,x[51];
  int i,n;
  for(;scanf("%d",&n),n;){
  for(i=1;i<=n;i++)scanf("%llu",x+i);
  for(r=0;n;r+=x[n],n--)
    for(i=1;i<n;i++)
      x[i]+=x[n];
  printf("%llu\n",r);
  }
}