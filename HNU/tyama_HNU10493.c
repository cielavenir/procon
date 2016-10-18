main(r,i,n){
  for(;scanf("%d",&n),n;printf("%d\n",r%10),r=1)
    for(i=2;i<=n;r%=10000,i++)
      for(r*=i;!(r%10);r/=10);
  return 0;
}