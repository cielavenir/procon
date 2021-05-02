#include <set>
#include <cstdio>
using namespace std;
int main(){
	int N,M,a,b,r=0;
	scanf("%d%d",&N,&M);
	multiset<pair<int,int>>n,m;
	multiset<int>s;
	for(int i=0;i<N;i++)scanf("%d%d",&a,&b),n.emplace(a,b);
	for(int i=0;i<M;i++)scanf("%d%d",&a,&b),m.emplace(b,a);
	auto it=m.begin();
	for(auto &e:n){
		for(;it!=m.end()&&it->first<=e.first;++it)s.insert(it->second);
		auto it2=s.lower_bound(e.second);
		if(it2!=s.end())r++,s.erase(it2);
	}
	printf("%d\n",r);
}