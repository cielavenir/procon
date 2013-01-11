//If we use memory algorithm, we'll get MLE.

#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
using namespace std;

int main(){
  int i,n,c,x,l;
  vector< pair<int,int> >v;
  scanf("%d%d",&n,&l);
  for(i=0;i<n;i++){
    scanf("%d%d",&c,&x);
    v.push_back(make_pair(c,x));
  }
  sort(v.begin(),v.end());
  for(c=x=i=0;i<n;i++){
    if(x>v[i].second)continue;
    if(x<v[i].first)x=v[i].first;
    int d=(v[i].second-x)/l+((v[i].second-x)%l?1:0);
    c+=d;x+=d*l;
  }
  printf("%d\n",c);
  return 0;
}