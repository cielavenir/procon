//gcj2011japanpractice === gcj2010q

#include <stdio.h>
int f(int n){
	int r=0;
	for(;n>0;n>>=1)r+=n&1;
	return r;
}
int main(){
	int t=1,T,N;
	for(scanf("%d",&T);t<=T;t++){
		scanf("%d",&N);
		int i=0,j,M=0,m;
		for(;i<=N/2;i++){
			j=N-i;
			m=f(i)+f(j);
			if(M<m)M=m;
		}
		printf("Case #%d: %d\n",t,M);
	}
}