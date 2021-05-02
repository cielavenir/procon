#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int main(){
  int i=0,n,m,x;
  vector<int> v;
  scanf("%d%d",&n,&m);
  for(;i<m;i++)scanf("%d",&x),v.push_back(x);
  sort(v.begin(),v.end(),greater<int>());
  for(x=i=1;i<=min(n,m);i++)
    if(x*v[x-1]<i*v[i-1])x=i;
  printf("%d %d\n",v[x-1],x*v[x-1]);
}