#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  unsigned n,i=0,x;
  vector<unsigned> v;
  scanf("%u",&n);
  for(;i<n;i++){
    scanf("%u",&x);
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  printf("%.1f",v.size()&1?v[n/2]:(v[n/2-1]+v[n/2])/2.0);
}