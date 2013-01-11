main(n,i,s,x,M,m){
  M=0,m=500;
  for(scanf("%d",&n);n;n--){
    for(i=s=0;i<5;i++)
      scanf("%d",&x),s+=x;
    if(m>s)m=s;
    if(M<s)M=s;
  }
  printf("%d %d\n",M,m);exit(0);
}