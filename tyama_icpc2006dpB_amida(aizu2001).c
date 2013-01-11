#include <stdio.h>
#include <string.h>

char x[101][1001];
main(m,a,h,p,q){
  for(;scanf("%d%d%d",&m,&m,&a),a;printf("%d\n",a)){
    for(memset(x,0,sizeof(x));m;m--)
      scanf("%d%d%d",&h,&p,&q),x[p][h]=q,x[q][h]=p;
    for(h=1000;h;h--)a=x[a][h]?x[a][h]:a;
  }
  return 0;
}