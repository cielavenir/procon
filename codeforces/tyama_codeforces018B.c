main(n,d,m,l){
  long long x,i;
  scanf("%d%d%d%d",&n,&d,&m,&l);
  for(i=0;i<n;i++){
    x = (l+i*m+d)/d*d;
    if(x<m*(i+1))break;
  }
  printf("%I64d\n",x);
  return 0;
}