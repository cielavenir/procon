#include<stdio.h>
long long M[16],Z[1<<16];int main(){
	int n,m,x,y,z;
	for(scanf("%d%d",&n,&m);m--;M[x-1]|=1<<(y-1))scanf("%d%d",&x,&y);
	for(m=1<<n,*Z=x=-1;++x<m;)for(y=-1;z=x|(1<<++y),y<n;)x-z&&!(M[y]&z)&&(Z[z]+=Z[x]);
	printf("%lld\n",-Z[m-1]);
}