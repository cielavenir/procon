#include <cstdio>
#include <algorithm>
int a[1001],b[510001],*p;main(){
	int n,m,i,j,k,r;
	for(;scanf("%d%d",&n,&m)>1&&n;printf("%d\n",r)){
		for(i=1;i<=n;i++)scanf("%d",a+i);
		for(k=i=0;i<=n;i++)for(j=i;j<=n;j++)b[k++]=a[i]+a[j];
		std::sort(b,b+k);
		for(r=i=0;b[i]<=m&&i<k;i++){
			p=std::upper_bound(b,b+k,m-b[i]);
			if(p>b&&r<b[i]+*(p-1))r=b[i]+*(p-1);
		}
	}
}