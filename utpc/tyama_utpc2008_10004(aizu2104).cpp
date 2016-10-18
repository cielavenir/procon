#include <cstdio>
#include <algorithm>
using namespace std;
int a[99999];
int main(){
  int c,n,k,i,x,y;
  for(scanf("%d",&c);c;printf("%d\n",x),c--){
    for(scanf("%d%d%d",&n,&k,&x),i=0;i<n-1;i++)
      scanf("%d",&y),a[i]=y-x,x=y;
    sort(a,a+n-1);
    for(x=i=0;i<n-k;i++)x+=a[i];
  }
}