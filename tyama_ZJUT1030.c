#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
main(){int x,y;for(;~scanf("%d%d",&x,&y);printf("%d\n",x/gcd(x,y)*y));}
