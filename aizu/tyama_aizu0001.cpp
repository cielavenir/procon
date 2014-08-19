#include <cstdio>
#include <algorithm>
#include <vector>
int main(){
  int i,x;
  std::vector<int>v;
  for(i=0;i<10;i++)scanf("%d",&x),v.push_back(x);
  std::sort(v.begin(),v.end());
  printf("%d\n%d\n%d\n",v[9],v[8],v[7]);
}