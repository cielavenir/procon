#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int i=0,j,x;
  float f;
  vector<pair<float,int> >v,w;
  for(;i<3;i++){
    for(j=0;j<8;j++)
      scanf("%d%f",&x,&f),v.push_back(make_pair(f,x));
    sort(v.begin(),v.end());
    printf("%d %.2f\n%d %.2f\n",v[0].second,v[0].first,v[1].second,v[1].first);
    w.push_back(make_pair(v[2].first,v[2].second));
    w.push_back(make_pair(v[3].first,v[3].second));
    v.clear();
  }
  sort(w.begin(),w.end());
  printf("%d %.2f\n%d %.2f\n",w[0].second,w[0].first,w[1].second,w[1].first);
}