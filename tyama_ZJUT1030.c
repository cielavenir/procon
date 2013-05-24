#include <stdio.h>
int G(int x,int y){return y?G(y,x%y):x;}
main(){int x,y;for(;~scanf("%d%d",&x,&y);printf("%d\n",x/gcd(x,y)*y));}