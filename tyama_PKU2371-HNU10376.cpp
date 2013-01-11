#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
  int n,i;
  vector<int>v;
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d",&i);
    v.push_back(i);
  }
  sort(v.begin(),v.end());
  for(i=5;i;i--)getchar();
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d",&i);
    printf("%d\n",v[i-1]);
  }
  return 0;
}