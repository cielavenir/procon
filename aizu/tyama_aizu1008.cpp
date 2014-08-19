#include <cstdio>
#include <map>
using namespace std;

int main(){
  int i,n,x,y;
  for(;scanf("%d",&n),n;printf(i==n?"NO COLOR\n":"%d\n",x)){
    map<int,int> m;
    for(i=0;i<n;i++){
      scanf("%d",&x);
      m[x]++;
      if(m[x]>n/2){for(;getchar()-10;);i=0;break;}
    }
  }
}