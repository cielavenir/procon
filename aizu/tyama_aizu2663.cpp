#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<long long>v(N+1);
	for(int i=1;i<=N;i++)scanf("%lld",&v[i]);
	sort(v.begin()+1,v.end());
	vector<long long>w(N+1);
	for(int i=1;i<=N;i++)w[i]=w[i-1]+v[i];
	int M;
	scanf("%d",&M);
	vector<long long>p(M);
	for(int i=0;i<M;i++){
		long long x;
		scanf("%lld",&x);
		auto it=upper_bound(v.begin(),v.end(),x);
		p[i]=w[distance(v.begin(),--it)];
	}
	for(int i=0;i<M;i++){
		long long x;
		scanf("%lld",&x);
		puts(p[i]>=x?"Yes":"No");
	}
}