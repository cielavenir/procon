#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long pow_binary_mod(long long x,long long y,long long m){
	long long z = 1;
	for(;y;y>>=1){
		if(y&1)z = z * x % m;
		x = x * x % m;
	}
	return z;
}

int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	vector<long long>v(N),d(N);
	for(int i=0;i<N;i++)scanf("%lld",&v[i]);
	for(int i=1;i<N;i++)d[i]=d[i-1]+pow_binary_mod(v[i-1],v[i],1000000007);
	int prev=0;
	long long r=0;
	for(int i=0;i<Q;i++){
		int x;
		scanf("%d",&x);x--;
		r+=llabs(d[x]-d[prev]);
		prev=x;
	}
	printf("%lld\n",(r+d[prev])%1000000007);
}