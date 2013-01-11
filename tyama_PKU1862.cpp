#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

int main(){
  std::vector<double> v;
  int s,x;
  scanf("%d",&s);
  for(;s--;){scanf("%d",&x);v.push_back(x);}
  std::sort(v.begin(),v.end());
  for(s=v.size()-1;~(s--);)v[s]=2*sqrt(v[s]*v[s+1]);
  printf("%.3f\n",v[0]);
  return 0;
}