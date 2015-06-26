#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
using namespace std;
map<vector<int>,int>memo;

int M,N;
vector<string>*vp;
int dfs(vector<int> &t){
	if(t.size()==1)return 0;
	if(memo.find(t)!=memo.end())return memo[t];
	int r=1<<30;
	for(int j=0;j<M;j++){
		vector<int>a,b;
		for(auto &e:t)(vp->at(e)[j]=='0'?a:b).push_back(e);
		if(a.size()&&b.size())r=min(r,max(dfs(a),dfs(b))+1);
	}
	return memo[t]=r;
}

int main(){
	for(;cin>>M>>N,M;){
		vector<string>v(N);
		vp=&v;
		for(int i=0;i<N;i++)cin>>v[i];
		vector<int>t(N);
		iota(t.begin(),t.end(),0);
		memo.clear();
		printf("%d\n",dfs(t));
	}
}