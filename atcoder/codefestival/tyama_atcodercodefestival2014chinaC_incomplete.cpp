//菱形について全く考慮していませんでした…悲しみ…。
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef unsigned long long diff_t;

diff_t diff(long long x,long long y){
	x=x<y?(y-x):(x-y);
	return (diff_t)(x)*x;
}
vector<int>ret;
void dfs(map<int,vector<int>>&m,vector<int>&v,set<int> &visited,int cur,int prev){
	for(auto &e:m[cur]){
		if(e!=prev){
			if(visited.find(e)!=visited.end()){
				if(ret.size()<v.size())ret=v;
			}else{
				v.push_back(e);
				visited.insert(e);
				dfs(m,v,visited,e,cur);
				v.pop_back();
			}
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);
	vector<pair<long long,long long>>v(N);
	for(int i=0;i<N;i++)scanf("%lld%lld",&v[i].first,&v[i].second);

	map<diff_t,map<int,vector<int>>>m;
	for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++){
		diff_t z=diff(v[i].first,v[j].first)+diff(v[i].second,v[j].second);
		m[z][i+1].push_back(j+1);
		m[z][j+1].push_back(i+1);
	}
	//close path in m
	for(auto &e:m){
		set<int>visited;
		for(auto &start:e.second){
			if(visited.find(start.first)==visited.end()){
				vector<int>z={start.first};
				visited.insert(start.first);
				dfs(e.second,z,visited,start.first,-1);
			}
		}
	}
	if(ret.size()!=0&&ret.size()!=4)return 1;
	sort(ret.begin(),ret.end());
	printf("%d\n",ret.size());
	for(auto &e:ret)printf("%d\n",e);
	return 0;
}