int reverse(int n){
  int r=0;
  while(n){r+=r+(n&1);n/=2;}
  return r;
}

main(n){for(;scanf("%d",&n),n;printf("%d\n",reverse(n)));}