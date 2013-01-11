#include <cstdio>
#include <algorithm>
using namespace std;

int a[100];
int main(){
  int n,i,r,s;
  for(;~scanf("%d",&n);printf("%d\n",r)){
    for(r=s=i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(i=0;i<n;i++)r+=s+=a[i];
  }
}