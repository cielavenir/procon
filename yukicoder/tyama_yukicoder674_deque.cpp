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
	long long ma=0;
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
		while(right_idx<se.size() && se[right_idx].first-1<=r){ // overlap with right
			r=max(r,se[right_idx].second);
			result-=se[right_idx].second-se[right_idx].first+1;
			se.erase(se.begin()+right_idx);
		}
		result+=r-l+1;
		se.insert(se.begin()+right_idx,make_pair(l,r));
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
