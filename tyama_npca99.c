#include <stdio.h>
long long a[20],f[20],r;
int b,n;
dfs(int i,int d,long long cur,long long total){ // generate bCn
	if(d==n){
		total+=cur*cur;
		if(r<total)r=total;
	}else if(i<b){
		dfs(i+1,d+1,cur+a[i],total);
		for(++i;i<b;i++)dfs(i+1,d+1,a[i],total+cur*cur);
	}
}
main(i){
	for(i=0,scanf("%d%d",&b,&n);i<b;i++)scanf("%lld",a+i);
	dfs(0,0,0,0);
	printf("%lld\n",r);
}