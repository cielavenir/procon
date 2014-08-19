#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int a,b,x,i;
  for(;scanf("%d%d",&a,&b),a|b;){
    vector<int> v;
    v.push_back(0);
    for(i=a+b;i;i--)
      scanf("%d",&x),v.push_back(x);
    sort(v.begin(),v.end());
    for(x=0,i=a+b;i;i--)
      if(v[i]-v[i-1]>x)x=v[i]-v[i-1];
    printf("%d\n",x);
  }
}