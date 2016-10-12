#include <cstdio>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
typedef int key;

int main(){
	int r,c,n;
	scanf("%d%d%d",&r,&c,&n);
	unordered_map<key,deque<pair<key,long long>>>m;
	for(;n;n--){
		int s1,s2,d;
		scanf("%d%d%d",&s1,&s2,&d);
		m[s1].emplace_back(s2+r,d);
		m[s2+r].emplace_back(s1,-d);
	}
	for(;!m.empty();){
		long long a=-1LL<<61,b=1LL<<61;
		auto s=m.begin()->first;
		deque<pair<key,long long>>st={{s,0}};
		unordered_map<key,long long>memo={{s,0}};
		for(;!st.empty();){
			auto p=*st.rbegin();st.pop_back();
			auto cur=p.first;long long d=p.second;
			for(auto &e:m[cur]){
				if(memo.find(e.first)==memo.end()){
					st.emplace_back(e.first,d+e.second);
					memo[e.first]=d+e.second;
				}else if(memo[e.first]!=d+e.second){
					puts("No");
					return 0;
				}
			}
			if(cur<=r)a=max(a,d);
			else b=min(b,d);
		}
		if(a>b){
			puts("No");
			return 0;
		}
		for(auto &e:memo)m.erase(m.find(e.first));
	}
	puts("Yes");
}
