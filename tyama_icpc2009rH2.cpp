#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
map<__uint128_t,int>memo;

int M,N;
vector<string>v;
int dfs(__uint128_t t){
	if(memo.find(t)!=memo.end())return memo[t];
	int c=0;
	for(int i=0;i<N;i++){
		if(t&(__uint128_t)(1)<<i)c++;
	}
	if(c==1)return 0;

	int r=1<<30;
	for(int j=0;j<M;j++){
		__uint128_t a=0,b=0;
		for(int i=0;i<N;i++){
			__uint128_t e=(__uint128_t)(1)<<i;
			if(t&e)(v[i][j]=='0'?a:b)|=e;
		}
		if(a&&b)r=min(r,max(dfs(a),dfs(b))+1);
	}
	return memo[t]=r;
}

int main(){
	for(;cin>>M>>N,M;){
		v.resize(N);
		for(int i=0;i<N;i++)cin>>v[i];
		__uint128_t t=0;
		for(int i=0;i<N;i++)t|=(__uint128_t)(1)<<i;
		memo.clear();
		printf("%d\n",dfs(t));
	}
}