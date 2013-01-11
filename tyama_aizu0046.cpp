#include <cstdio>
#include <algorithm>
#include <vector>
int main(){
  float f;
  std::vector<float>v;
  for(;~scanf("%f",&f);)v.push_back(f);
  std::sort(v.begin(),v.end());
  printf("%.2f\n",v[v.size()-1]-v[0]);
}