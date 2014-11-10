#include <unordered_set>
#include <map>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<long long,long long> pll;
int main(){
	long long first,second,k;
	scanf("%lld%lld%lld",&first,&second,&k);
	unordered_set<long long>lst={0};
	map<pll,long long>depth={{{0,0},0}};
	deque<pll>q={{0,0}};
	for(;!q.empty();){
		pll x=q.front();
		q.pop_front();
		vector<pll>a={
			{first,x.second},
			{x.first,second},
			{0,x.second},
			{x.first,0},
			{x.first-min(x.first,second-x.second),x.second+min(x.first,second-x.second)},
			{x.first+min(first-x.first,x.second),x.second-min(first-x.first,x.second)},
		};
		for(auto &e:a){
			if(depth.find(e)==depth.end() && depth[x]<k){
				lst.insert(e.first);
				lst.insert(e.second);
				depth[e]=depth[x]+1;
				q.push_back(e);
			}
		}
	}
	printf("%d\n",lst.size());
	return 0;
}