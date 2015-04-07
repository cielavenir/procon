#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	vector<long long>v(N+1);
	for(int i=0;i<N;i++)scanf("%lld",&v[i+1]),v[i+1]+=v[i];
	for(int i=0;i<Q;i++){
		long long l;
		scanf("%lld",&l);
		auto it=lower_bound(v.begin(),v.end(),l);
		if(it==v.end())puts("-1");
		else printf("%d\n",distance(v.begin(),it));
	}
}