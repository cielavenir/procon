#include <cstdio>
#include <algorithm>
int a[11],t,i;main(){for(scanf("%d",&t);t--;std::sort(a+1,a+11),printf("%d %d\n",*a,a[8]))for(i=0;i<11;i++)scanf("%d",a+i);}