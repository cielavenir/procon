#include <unordered_map>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<long long,long long> pll;

long long checkio(const vector<pll> &v){
	long long result=0;
	long long l,r;
	deque<pll> se;
	for(auto &e:v){
		l=e.first,r=e.second;
		auto right=lower_bound(se.begin(),se.end(),make_pair(l,0LL)); //l <= se[right_idx].first
		size_t right_idx=right-se.begin();
		if(right_idx!=0){
			size_t left_idx=right_idx-1;
			if(l<=se[left_idx].second+1){ // overlap with left
				l=se[left_idx].first;
				r=max(r,se[left_idx].second);
				result-=se[left_idx].second-se[left_idx].first+1;
				se.erase(se.begin()+left_idx);
				right_idx--;
			}
		}
		while(right_idx<se.size() && se[right_idx].first<=r){ // overlap with right
			r=max(r,se[right_idx].second);
			result-=se[right_idx].second-se[right_idx].first+1;
			se.erase(se.begin()+right_idx);
		}
		result+=r-l+1;
		se.insert(se.begin()+right_idx,make_pair(l,r));
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