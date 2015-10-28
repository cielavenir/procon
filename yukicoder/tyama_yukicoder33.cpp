#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<long long,long long> pll;

long long checkio(const vector<pll> &v){
	long long result=0;
	long long l,r;
	set<pll> se;
	for(auto &e:v){
		l=e.first,r=e.second;
		auto right=se.lower_bound(make_pair(l,0LL)); //p.first <= right.first
		if(right!=se.begin()){
			--right;
			auto left=right;
			++right;
			if(l<=left->second+1){ // overlap with left
				l=left->first;
				r=max(r,left->second);
				result-=left->second-left->first+1;
				se.erase(left);
			}
		}
		while(right!=se.end() && right->first<=r){ // overlap with right
			r=max(r,right->second);
			result-=right->second-right->first+1;
			se.erase(right++);
		}
		result+=r-l+1;
		se.insert(make_pair(l,r));
	}
	return result;
}

int main(){
	unordered_map<long long,vector<pll>> dic;
	long long n,d,t,x,m;
	scanf("%lld%lld%lld",&n,&d,&t);
	for(int i=0;i<n;i++){
		scanf("%lld",&x);
		m=(x%d+d)%d;
		dic[m].emplace_back((x-m)/d-t,(x-m)/d+t);
	}
	x=0;
	for(auto &e:dic)x+=checkio(e.second);
	printf("%lld\n",x);
}