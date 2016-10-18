#include <string>
#include <cstdio>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
typedef string key;

char b1[99],b2[99];
void main2(int n){
	unordered_map<key,deque<pair<key,long long>>>m;
	for(;n;n--){
		int d;
		scanf(" 1 %s = 10^%d %s",b1,&d,b2);
		string s1=b1,s2=b2;
		m[s1].emplace_back(s2,d);
		m[s2].emplace_back(s1,-d);
	}
	for(;!m.empty();){
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
					return;
				}
			}
		}
		for(auto &e:memo)m.erase(m.find(e.first));
	}
	puts("Yes");
}
int main(){int n;for(;~scanf("%d",&n)&&n;)main2(n);}
