#include <algorithm>
#include <cstdio>

int a[99],b[99];
int main(){
  int i,j,n;
  scanf("%d",&n);
  for(i=0;i<n;std::sort(a,a+n),b[i]=a[n/2],i++)
    for(j=0;j<n;j++)
      scanf("%d",a+j);
  std::sort(b,b+n);
  printf("%d\n",b[n/2]);
  return 0;
}