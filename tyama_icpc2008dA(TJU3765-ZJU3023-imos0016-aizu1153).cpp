#include <stdio.h>
#include <algorithm>

using namespace std;
int t[100],h[100];

int main(){
  int _t,_h,ts,hs,i,j,x;
  loop:
    scanf("%d%d",&_t,&_h);
    if(!_t)return 0;
    ts=0;hs=0;
    for(i=0;i<_t;i++){
      scanf("%d",t+i);
      ts+=t[i];
    }
    for(i=0;i<_h;i++){
      scanf("%d",h+i);
      hs+=h[i];
    }
    x=ts-hs;
    if(x&1)goto fail;
    x/=2;
    sort(t,t+_t);
    sort(h,h+_h);

    for(i=0;i<_t;i++)
      for(j=0;j<_h;j++)
        if(x == t[i]-h[j]){
          printf("%d %d\n",t[i],h[j]);
          goto loop;
        }
  fail:
    printf("-1\n");
    goto loop;
}