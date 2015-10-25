#include <cstdio>
#include <set>
using namespace std;
typedef pair<long long,long long> pll;

int main(){
	long long l,v,r;
	set<pll> se;
	for(scanf("%lld",&l);~scanf("%lld%lld",&l,&v);){
		r=l+v-1;
		auto right=se.lower_bound(make_pair(l,0LL)); //p.first <= right.first
		for(;l<=r;){
			long long consumed=0;
			if(right!=se.begin()){
				--right;
				auto left=right;
				++right;
				if(l<=left->second+1){ // overlap with left (範囲を+1することで左に接しているのもマージ)
					consumed-=left->second - left->first + 1;
					l=left->first;
					r=max(r,left->second);
					//result-=left->second-left->first+1;
					se.erase(left);
				}
			}
			while(right!=se.end() && right->first<=r){ // overlap with right
				consumed-=right->second - right->first + 1;
				r=max(r,right->second);
				//result-=right->second-right->first+1;
				se.erase(right++);
			}
			//result+=r-l+1;
			//result2+=r-l+1;
			consumed+=r-l+1;
			se.insert(right,make_pair(l,r));
			v-=consumed;
			l=r+1;
			r=l+v-1;
		}
		printf("%lld\n",r);
	}
}