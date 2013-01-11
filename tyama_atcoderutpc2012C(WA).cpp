#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
map<int,int>visit;
map<int,vector<int> >m;
int D(int parent,int node){
	int i=0;
	//printf("---%d %d\n",parent,node);
	vector<int>v=m[node];
	visit[node]=1;
	for(;i<v.size();i++){
		//printf("+++%d\n",v[i]);
		if(visit[v[i]]&&parent==v[i])return 1;
		if(!visit[v[i]]&&D(node,v[i]))return 1;
	}
	return 0;
}
int main(){
	int i,n,M,s,t;
	for(scanf("%d%d",&n,&M);M;M--){
		scanf("%d%d",&s,&t);
		auto its=find(m[s].begin(),m[s].end(),t);
		if(its==m[s].end())m[s].push_back(t);else m[s].erase(its);
		auto itt=find(m[t].begin(),m[t].end(),s);
		if(itt==m[t].end())m[t].push_back(s);else m[t].erase(itt);
		visit.clear();
		for(i=1;i<=n;i++)if(D(-1,i))break;
		puts(i>n?"no":"yes");
	}
}