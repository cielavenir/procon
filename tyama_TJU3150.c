int gcd2(x,y){if(!y)return x;return gcd2(y,x%y);}
int gcd(x,y){return x>y?gcd2(x,y):gcd2(y,x);}
main(i,x,y,g){for(gets(&x);~scanf("%d%d",&x,&y);printf("%d %d %d\n",i++,x/g*y,g))g=gcd(x,y);}