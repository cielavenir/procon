#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(){
  vector<int>v;
  int n,h,i,s=0;
  for(scanf("%d%d",&n,&h);n;n--){
    scanf("%d",&i);
    v.push_back(i);
  }
  sort(v.begin(),v.end(),greater<int>());
  for(i=0;s<h;i++)s+=v[i];
  printf("%d\n",i);
  return 0;
}