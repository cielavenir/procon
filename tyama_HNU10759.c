int gcd2(int x,int y){if(!y)return x;return gcd2(y,x%y);}
int gcd(int x,int y){return x>y?gcd2(x,y):gcd2(y,x);}
main(n,a,b){for(;scanf("%d",&n),n;){scanf("%d",&a);for(n--;n;n--){scanf("%d",&b);a=(!a||!b)?0:a/gcd(a,b)*b;}printf("%d\n",a);}exit(0);}