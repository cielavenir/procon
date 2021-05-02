#include <set>
#include <cstdio>
using namespace std;

void solve(){
  int i,j,x;
  set<int> s,t;
  set<int>::iterator e;

  scanf("%d%d",&i,&j);
  for(;i--;scanf("%d",&x),s.insert(x));
  for(;j--;scanf("%d",&x),t.insert(x));
  for(x=0,e=s.begin();e!=s.end();e++)
    if(t.find(*e)!=t.end()){
      if(x)printf(" ");
      printf("%d",*e);
      x=1;
    }
}

int main(){int i;for(scanf("%d",&i);i--;solve(),puts(""));return 0;}