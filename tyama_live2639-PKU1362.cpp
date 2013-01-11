#include <vector>
#include <string>
#include <cstdio>
using namespace std;

void solve(int x){
  vector<int> v;
  int n=67108864,i=25;
  if(!x)return;
  for(;x;n/=2,i--){
    if(x>n-1){v.push_back(i);x-=n-1;}
    if(x==n-1){v.push_back(i);x-=n-1;}
  }
  for(i=v.size()-1;i;i--)printf("%d,",v[i]);
  printf("%d",v[0]);
}
int main(){int n,x;for(scanf("%d",&n);n--;scanf("%d",&x),printf("%d [",x),solve(x),puts("]"));}