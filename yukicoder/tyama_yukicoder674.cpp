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
	long long ma=0;
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
		while(right!=se.end() && right->first-1<=r){ // overlap with right
			r=max(r,right->second);
			result-=right->second-right->first+1;
			se.erase(right++);
		}
		result+=r-l+1;
		se.insert(make_pair(l,r));
		ma=max(ma,r-l+1);
		printf("%lld\n",ma);
	}
	return result;
}

int main(){
	vector<pll>data;
	long long a,b;
	scanf("%lld%lld",&a,&b);
	for(;~scanf("%lld%lld",&a,&b);){
		data.emplace_back(a,b);
	}
	checkio(data);
}
