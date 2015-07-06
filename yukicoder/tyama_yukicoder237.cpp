// http://yukicoder.me/submissions/35279
#include <vector>
#include <stdio.h>
#define N 1000000000
//long long T[N+1],totient[N+1];
long long pow_binary(long long x,long long y){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=z*x;
		x=x*x;
	}
	return z;
}
int main(){
	std::vector<long long> T(N+1),totient(N+1);
	puts("allocated.");
	for(int i=0;i<=N;i++)T[i]=i,totient[i]=1;
	for(int i=2;i<=N;i++)if(T[i]>1){
		printf("%d-",i);
		for(int j=i;j<=N;j+=i){
			int n=0;
			for(;T[j]%i==0;){
				T[j]/=i;
				n++;
			}
			if(n)totient[j]*=(i-1)*pow_binary(i,n-1);
		}
	}
	for(int i=3;i<=N;i++){
		if(__builtin_popcountll(totient[i])==1)printf("%d,\n",i);
	}
}