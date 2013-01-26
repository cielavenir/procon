#include <cstdio>
#include <algorithm>

int x[1000000]; /* 1000 for 1003 */
int main(){
  int n,i=0;
  scanf("%d",&n);
  for(;i<n;i++)scanf("%d",x+i);
  std::sort(x,x+n);
  for(i=0;i<n-1;i++)printf("%d ",x[i]);
  printf("%d\n",x[i]);
  return 0;
}