#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef vector<pair<int, int> > vp;

int solve(vp &v){
  int r=0,i=0;
  for(;i<v.size()-1;i++)r+=min(v[i+1].first,v[i].second)-v[i].first;
  return r+v[i].second-v[i].first;
}

int main(){
  int n,d,x;
  scanf("%d%d",&n,&d);
  vp v;
  for(;n;n--)scanf("%d",&x),v.push_back(make_pair(x,x+d));
  sort(v.begin(),v.end());
  printf("%d\n",solve(v));
}