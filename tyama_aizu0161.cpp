#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int n,i,a,b,c,d,e,f,g,h;
  for(;scanf("%d",&n),n;){
    vector<pair<int,int> >v;
    for(;n--;)scanf("%d%d%d%d%d%d%d%d%d",&i,&a,&b,&c,&d,&e,&f,&g,&h),v.push_back(make_pair(a*60+b+c*60+d+e*60+f+g*60+h,i));
    sort(v.begin(),v.end());
    printf("%d\n%d\n%d\n",v[0].second,v[1].second,v[v.size()-2].second);
  }
}