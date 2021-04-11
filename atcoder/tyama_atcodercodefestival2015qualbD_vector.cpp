#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
typedef pair<long long,long long> pll;

int main(){
	long long l,v,r;
	deque<pll> se;
	for(scanf("%lld",&l);~scanf("%lld%lld",&l,&v);){
		r=l+v-1;
		auto right=lower_bound(se.begin(),se.end(),make_pair(l,0LL)); //l <= se[right_idx].first
		size_t right_idx=right-se.begin();
		for(;l<=r;){
			long long consumed=0;
			if(right_idx!=0){
				size_t left_idx=right_idx-1;
				if(l<=se[left_idx].second+1){ // overlap with left
					consumed-=se[left_idx].second - se[left_idx].first + 1;
					l=se[left_idx].first;
					r=max(r,se[left_idx].second);
					//result-=se[left_idx].second-se[left_idx].first+1;
					se.erase(se.begin()+left_idx);
					right_idx--;
				}
			}
			while(right_idx<se.size() && se[right_idx].first<=r){ // overlap with right
				consumed-=se[right_idx].second - se[right_idx].first + 1;
				r=max(r,se[right_idx].second);
				//result-=se[right_idx].second-se[right_idx].first+1;
				se.erase(se.begin()+right_idx);
			}
			//result+=r-l+1;
			//result2+=r-l+1;
			consumed+=r-l+1;
			se.insert(se.begin()+right_idx,make_pair(l,r));
			right_idx++;
			v-=consumed;
			l=r+1;
			r=l+v-1;
		}
		printf("%lld\n",r);
	}
}