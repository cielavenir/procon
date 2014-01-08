#include <stdio.h>
int i,n,N=1;main(){for(scanf("%d",&n);n--;N*=2);for(;i<N;i++)printf("%d\n",i^(i>>1));}