#include <stdio.h>
long long c[200000],p[200000];
int main(){
	long long pop,dist,r;
	int i,j,N,T;
	for(scanf("%d\n",&T);T--;printf("%lld\n",r)){
		scanf("%d",&N);
		for(i=0;i<N;i++)scanf("%lld",c+i);
		for(i=0;i<N;i++)scanf("%lld",p+i);
		for(r=i=0;i<N-1;i++)for(j=i+1;j<N;j++){
			pop=p[i]>p[j]?p[i]:p[j];
			dist=c[j]-c[i];
			if(dist<0)dist=-dist;
			r=(r+pop*dist)%1000000007;
		}
	}
}