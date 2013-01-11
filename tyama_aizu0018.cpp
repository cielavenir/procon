#include<cstdio>
#include<algorithm>
int main(){for(int a[5];~scanf("%d%d%d%d%d",a,a+1,a+2,a+3,a+4);printf("%d %d %d %d %d\n",a[4],a[3],a[2],a[1],a[0]))std::sort(a,a+5);}