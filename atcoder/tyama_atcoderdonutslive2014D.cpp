#include <map>
#include <cstdio>
using namespace std;
map<pair<int,int>,int>memo;
int dfs(int n,int m){
	if(n<m)return 0;
	if(m==1||n==m)return 1;
	pair<int,int> z=make_pair(n,m);
	if(memo.find(z)!=memo.end())return memo[z];
	return memo[z]=((long long)dfs(n-1,m)*m+dfs(n-1,m-1))%1000000007;
}
int main(){int n,m;scanf("%d%d",&n,&m);printf("%d\n",dfs(n,m));}