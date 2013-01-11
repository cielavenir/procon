main2(n){
  int i,s,x,M=0,m=500;
  for(;n;n--){
    for(i=s=0;i<5;i++)
      scanf("%d",&x),s+=x;
    if(m>s)m=s;
    if(M<s)M=s;
  }
  printf("%d %d\n",M,m);
}
main(n){for(;scanf("%d",&n),n;)main2(n);exit(0);}