#include <stdio.h>
unsigned long long isqrt(unsigned long long n){
  if(n<=0)return 0;
  if(n<4)return 1;
  unsigned long long x=0,y=n;
  for(;x!=y&&x+1!=y;)x=y,y=(n/y+y)/2;
  return x;
}
int main(){
  unsigned long long n;
  scanf("%llu",&n);
  unsigned long long x=n*8+1,q=isqrt(x);
  if(q*q!=x||q%2==0)puts("NO");
  else printf("YES\n%llu\n",q-1>>1);
}
