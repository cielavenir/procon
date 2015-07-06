#include <vector>
#include <cstdio>
using namespace std;
#define M 1000000007
long long pow_binary_mod(long long x,long long y){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=z*x%M;
		x=x*x%M;
	}
	return z;
}
vector<int>F;
int comb(int N,int K){
	return F[N] * pow_binary_mod(F[K],M-2)%M * pow_binary_mod(F[N-K],M-2)%M;
}
int main(){
	int N,R=0;
	scanf("%d",&N);
	F.resize(N+1);F[0]=1;
	for(int i=1;i<=N;i++)F[i]=(long long)F[i-1]*i%M;
	for(int i=0;i<N;i++){
		R=(comb(N,i)*pow_binary_mod(2,(long long)i*(i-1)/2 + (long long)(N-i)*(N-i-1)/2)%M + R)%M;
	}
	printf("%d\n",R);
	return 0;
}