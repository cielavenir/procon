#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int solve(int n){
  vector<int>v;
  int i=0,r;
  for(;i<n;i++){scanf("%d",&r);v.push_back(r);}
  sort(v.begin(),v.end(),greater<int>());
  for(r=0,i=2;i<n;i+=3)r+=v[i];
  return r;
}

int main(){
  int n,x;
  for(scanf("%d",&n);n;n--){
    scanf("%d",&x);
    printf("%d\n",solve(x));
  }
  return 0;
}