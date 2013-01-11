int daffodil(int _n){
  int n=_n,r=0,x;
  while(n){
    x=n%10;r+=x*x*x;
    n/=10;
  }
  return _n==r;
}

main(n){for(;~scanf("%d",&n);printf(daffodil(n)?"Yes\n":"No\n"));}