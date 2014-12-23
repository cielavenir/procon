#include <stdio.h>
int main(){
	int T,N;
	for(scanf("%d",&T);T--;){
		scanf("%d",&N);
		int i=0;
		long long s=0,mt=0,t=0,n,ma=-99999;
		for(;i<N;i++){
			scanf("%lld",&n);
			if(ma<n)ma=n;
			if(n>0)s+=n;
			t+=n;
			if(t<0)t=0;
			if(mt<t)mt=t;
		}
		if(ma>=0){
			printf("%lld %lld\n",mt,s);
		}else{
			printf("%lld %lld\n",ma,ma);
		}
	}
	return 0;
}