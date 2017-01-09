#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main(){
	int N;
	long long V,R=0;
	scanf("%d%lld",&N,&V);
	vector<long long>a(N),b(N),c(N),d(N);
	for(int i=0;i<N;i++)scanf("%lld",&a[i]);
	for(int i=0;i<N;i++)scanf("%lld",&b[i]);
	for(int i=0;i<N;i++)scanf("%lld",&c[i]);
	for(int i=0;i<N;i++)scanf("%lld",&d[i]);
	map<long long,long long>m1,m2;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)m1[a[i]+b[j]]++;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)m2[c[i]+d[j]]++;
	for(auto &e:m1){
		auto it=m2.lower_bound(V-e.first);
		if(it!=m2.end()&&it->first==V-e.first)R+=e.second*it->second;
	}
	printf("%lld\n",R);
}
