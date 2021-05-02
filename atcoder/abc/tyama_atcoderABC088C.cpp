#include <string>
#include <cstdio>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;
typedef int key;

int main(){
	int N=3;
	unordered_map<key,deque<pair<key,long long>>>m;
	for(int i=0;i<N*N;i++){
		int k;
		scanf("%d",&k);
		m[i/N+N].emplace_back(i%N,k);
		m[i%N].emplace_back(i/N+N,-k);
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
					return 0;
				}
			}
		}
		for(auto &e:memo)m.erase(m.find(e.first));
	}
	puts("Yes");
}
