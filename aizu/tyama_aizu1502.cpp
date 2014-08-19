#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;
int a[999],i;main(){int n,j;
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	sort(a,a+n,greater<int>());
	long long r=1;
	for(i=0;i<n&&(j=a[i]-i/4)>0;i++)r+=j;
	i=!printf("%lld\n",r);
}