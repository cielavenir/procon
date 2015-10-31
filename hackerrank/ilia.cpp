#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N;
	long long r=0,s=0,t=0;
	scanf("%d",&N);
	vector<long long>v(N),w(N);
	for(int i=0;i<N;i++)scanf("%lld",&v[i]),w[i]=v[i]*v[i];
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
		int end_idx=lower_bound(v.begin()+j+1,v.end(),v[i]+v[j])-v.begin();
		auto equal=equal_range(w.begin()+j+1,w.begin()+end_idx,w[i]+w[j]);
		r+=equal.first-(w.begin()+j+1);
		s+=equal.second-equal.first;
		t+=w.begin()+end_idx-equal.second;
	}
	printf("%lld %lld %lld\n",r,s,t);
}