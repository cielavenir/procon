#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	vector<long long>A(N),B(M);
	long long SA=0,SB=0,R=0;
	for(int i=0;i<N;i++)scanf("%lld",&A[i]),SA+=A[i];
	for(int i=0;i<M;i++)scanf("%lld",&B[i]),SB+=B[i];

	if(K>1)return 1;
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)R=max(R,(SA-A[i]+B[j])*(SB-B[j]+A[i]));
	printf("%lld\n",R);
}