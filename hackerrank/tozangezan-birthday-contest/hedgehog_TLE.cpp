#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	long long v[1000];
	long long R=0;
	int N,M;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&M);
		for(int j=0;j<M;j++)scanf("%lld",&v[j]);
		std::sort(v,v+M);
		for(int j=1;j<M;j++)R^=v[j]*j;
	}
	printf("%lld\n",R);
}