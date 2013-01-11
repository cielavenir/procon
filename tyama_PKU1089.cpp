#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector< pair<int,int> > v;
  int n,x,y;
  for(scanf("%d",&n);n--;){scanf("%d%d",&x,&y);v.push_back(make_pair(x,y));}
  sort(v.begin(),v.end());
  x=v[0].first;y=v[0].second;
  for(n=1;n<v.size();n++){
    if(y<v[n].first){
      printf("%d %d\n",x,y);
      x=v[n].first;y=v[n].second;
    }
    if(y<v[n].second)
      y=v[n].second;
  }
  printf("%d %d\n",x,y);
  return 0;
}