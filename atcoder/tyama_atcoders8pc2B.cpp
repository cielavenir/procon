#include <stdio.h>
long long N;
int Q,d[24],i;
int f(int i,long long x){return x>N?0:i<0?1:f(i-1,x*d[i])+(x%d[i]?f(i-1,x):0);}
int main(){scanf("%lld%d",&N,&Q);for(;i<Q;i++)scanf("%d",&d[i]);i=!printf("%d\n",f(Q-1,1));}