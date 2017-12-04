#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<int>>lst;
unordered_map<long long,pair<int,int>>m;

pair<int,int> dfs(int d,int cur){
	long long key=(long long)d<<32|cur;
	if(m.find(key)!=m.end())return m[key];
	pair<int,int> r={cur,cur};
	if(cur>0){
		auto it=upper_bound(lst[cur].begin(),lst[cur].end(),d);
		if(it!=lst[cur].end()){
			r.first=dfs(*it,cur-1).first;
		}
	}
	if(cur<lst.size()-1){
		auto it=upper_bound(lst[cur+1].begin(),lst[cur+1].end(),d);
		if(it!=lst[cur+1].end()){
			r.second=dfs(*it,cur+1).second;
		}
	}
	return m[key]=r;
}

int main(){
	int n,k;
	for(;~scanf("%d%d",&n,&k);){
	lst.clear();m.clear();
	vector<pair<int,int>>v(k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&v[i].first,&v[i].second);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	lst.resize(n);
	for(int i=0;i<k;i++){
		lst[v[i].second].push_back(i);
	}
	for(int i=0;i<n;i++){
		auto p=dfs(-1,i);
		printf(i<n-1 ? "%d " : "%d\n",p.second-p.first+1);
	}
	}
}
