#include <vector>
#include <map>
#include <cstdio>
using namespace std;

map<int,int>memo;
map<int,vector<int> >v;
int dfs(int prev,int cur){
	for(auto &nxt:v[cur]){
		if(nxt==prev)continue;
		if(memo[nxt])return memo[cur]-memo[nxt]+1;
		memo[nxt]=memo[cur]+1;
		int ret=dfs(cur,nxt);
		if(ret)return ret;
	}
	return 0;
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	memo[1]=1;
	printf("%d\n",dfs(-1,1));
}