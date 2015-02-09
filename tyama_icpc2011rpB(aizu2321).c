#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

map<int,int>memo;
vector<int>S,T;
int n;

int dfs(int t){
	if(memo.find(t)!=memo.end())return memo[t];
	int r=0;
	for(int i=0;i<n;i++)if((t&T[i])==T[i]){
		int x=S[i]+dfs(t&(~T[i]));
		if(r<x)r=x;
	}
	return memo[t]=r;
}

int main(){
	for(;scanf("%d",&n),n;){
		memo.clear();
		S.resize(n);
		T.resize(n);
		fill(T.begin(),T.end(),0);
		for(int i=0;i<n;i++){
			int m;
			for(scanf("%d%d",&m,&S[i]);m--;){
				int st,en;
				scanf("%d%d",&st,&en);
				for(int j=st-6;j<en-6;j++)T[i]|=1<<j;
			}
		}
		printf("%d\n",dfs(0xffff));
	}
}