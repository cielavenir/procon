#include <map>
#include <set>
#include <cstdio>
using namespace std;
map<int,int>m;
void dfs(set<int>&v,int cur){
	v.insert(cur);
	if(cur)dfs(v,m[cur]);
}
main(){
	int n,i=0,j,x;
	for(scanf("%d",&n);i<n;i++)for(scanf("%d",&j);j--;)scanf("%d",&x),m[x]=i;
	for(scanf("%d",&n);n--;){
		scanf("%d%d",&i,&j);
		set<int>v;
		dfs(v,i);
		for(;v.find(j)==v.end();)j=m[j];
		printf("%d\n",j);
	}
}