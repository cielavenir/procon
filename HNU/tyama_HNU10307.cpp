#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

void solve(int n){
  vector<int> v;
  int x=0,y;
  for(;n;n--){
    scanf("%d",&y);
    v.push_back(y-x);
    x=y;
  }
  sort(v.begin(),v.end());
  for(;n<v.size();n++){
    if(n)printf(" ");
    printf("%d",v[n]);
  }
  puts("");
}

int main(){int t,n,i=0;for(scanf("%d",&t);i<t;){if(i)puts("");printf("Case %d:\n",++i);scanf("%d",&n);solve(n);}return 0;}