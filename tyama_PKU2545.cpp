//Valid only on VC++. This situation is happening because of the treatment of __int64, I think.
#include <iostream>
#include <set>
using namespace std;

int main(){
  set<__int64> s;
  int x,i=0;
  __int64 a,b,c,t;
  scanf("%I64d%I64d%I64d%d",&a,&b,&c,&x);
  s.insert(a);
  s.insert(b);
  s.insert(c);
  set<__int64>::iterator ite=s.begin();
  while(i<x){
    t=*ite;
    if(t*a>t)s.insert(t*a);
    if(t*b>t)s.insert(t*b);
    if(t*c>t)s.insert(t*c);
    i++;ite++;
  }
  ite=s.begin();
  for(i=0;i<x-1;i++,ite++);
  printf("%lld\n",*ite);
  return 0;
}