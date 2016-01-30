#include <deque>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,ma=0;
	scanf("%d",&N);
	deque<int>v(N);
	{
		set<int>lst;
		for(int i=0;i<N;i++){
			scanf("%d",&v[i]);
			lst.insert(v[i]);
		}
		map<int,int>m;
		int n=0;
		for(auto &e:lst)m[e]=++ma;
		for(int i=0;i<N;i++)v[i]=m[v[i]];
	}
#if 1
	if(N==1){
		puts("1");
		return 0;
	}
	map<int,vector<int>>m;
	for(int i=0;i<N;i++)m[v[i]].push_back(i);
	int last=0;
	long long d=0;
	for(int x=1;x<=ma;x++){
		auto it=lower_bound(m[x].begin(),m[x].end(),last);
		if(it==m[x].begin()){
			auto it2=lower_bound(m[x].begin(),m[x].end(),N);
			--it2;
			d+=*it2-last;
			last=*it2;
		}else{
			--it;
			d+=N-(last-*it);
			last=*it;
		}
	}
	printf("%lld\n",(d+N-1)/N);
#else
	map<int,int>cnt;
	for(auto &e:v)cnt[e]+=1;
	int x=1;
	if(v[0]==x){
		cnt[x]--;
		if(cnt[x]==0)x++;
	}
	rotate(v.begin(),v.begin()+1,v.end());
	for(int r=1;;r++){
		auto it=v.begin();
		for(;it!=v.end();){
			if(*it==x){
				cnt[x]--;
				if(cnt[x]==0)x++;
				it=v.erase(it);
			}else{
				++it;
			}
		}
		if(x>ma){
			printf("%d\n",r);
			break;
		}
	}
#endif
}