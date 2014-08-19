#include <cstdio>
#include <set>
#define M 1000001
using namespace std;

int a[M];
int main(){
  set<int> s;
  int t,u;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(5);
  set<int>::iterator ite=s.begin();
  while((t=*ite)<M){
    if(t*2>t)s.insert(t*2);
    if(t*3>t)s.insert(t*3);
    if(t*5>t)s.insert(t*5);
    ite++;
  }
  for(ite=s.begin();*ite<M;ite++)a[*ite]=1;
  for(t=0;t<M;t++)a[t]+=a[t-1];
  for(;scanf("%d",&t),t;printf("%d\n",a[u]-a[t-1]))
  scanf("%d",&u);
}