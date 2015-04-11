int gcd(x,y){return y?gcd(y,x%y):x;}
main(n,m){for(;~scanf("%d%d",&n,&m);)printf("%10d%10d    %s Choice\n\n",n,m,gcd(n,m)>1?"Bad":"Good");}