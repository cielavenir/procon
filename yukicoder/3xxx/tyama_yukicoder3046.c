#pragma GCC optimize("O3")
#pragma GCC target("avx")
#include <stdio.h>
int k[1<<17],x[1<<17];
const int M=1000000007;
int main(){
	int K,N;
	scanf("%d%d",&K,&N);
	k[0]=1;
	for(int i=0,y;i<N;i++)scanf("%d",&y),x[y]=1;
	for(int l=0;l<K;l++){
		int v=k[l];
		for(int i=0;l+i<=K;i++){
			k[l+i]+=x[i]*v;
			if(k[l+i]>=M)k[l+i]-=M;
		}
	}
	printf("%d\n",k[K]);
}
