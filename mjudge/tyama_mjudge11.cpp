#include <cstdio>
#include <set>
int main(){
  std::set<int> s;
  int n,m,x,c;
  for(;~scanf("%d%d",&n,&m);printf("%d\n",c)){
    for(s.clear(),c=0;n--;s.insert(x))scanf("%d",&x);
    for(;m--;)if(scanf("%d",&x),s.find(x)!=s.end())c++;
  }
}