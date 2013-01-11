main(){
  unsigned long long i,j,k;
  int r;
  for(;scanf("%I64d%I64d",&i,&j),i;){
    k=i^j;
    for(r=0;k;r+=k&1?1:0,k/=2);
    printf("%d\n",r);
  }
  return 0;
}