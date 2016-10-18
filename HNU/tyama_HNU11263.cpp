#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
  int n,g,m,x;
  scanf("%d",&n);
  for(;n;n--){
    vector< pair<int,int> >v;
    scanf("%d%d",&g,&m);
    for(;g;g--)scanf("%d",&x),v.push_back(make_pair(x,1));
    for(;m;m--)scanf("%d",&x),v.push_back(make_pair(x,0));
    sort(v.begin(),v.end());
    printf("%sGodzilla\n",!v.back().second?"Mecha":"");
  }
  return 0;
}