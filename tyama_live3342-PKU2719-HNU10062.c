x(n){return (n%=10)<4?n:n-1;}
o(n){return n/10?o(n/10)*9+x(n):x(n);}
main(n){for(;scanf("%d",&n),n;printf("%d: %d\n",n,o(n)));}