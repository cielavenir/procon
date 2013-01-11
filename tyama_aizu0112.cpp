#include <cstdio>
#include <algorithm>
using namespace std;

int a[10000];
int main(){
  int n,i;
  long long z,r;
  for(;scanf("%d",&n),n;printf("%lld\n",r)){
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(z=r=i=0;i<n-1;i++)z+=a[i],r+=z;
  }
}