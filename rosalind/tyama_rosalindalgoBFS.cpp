#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int vis[1001];
int main(){
	int n,m,x,y,i=0;
	memset(vis,0xff,sizeof(vis));
	map<int,vector<int> >M;
	for(scanf("%d%d",&n,&m);i<m;i++)scanf("%d%d",&x,&y),M[x].push_back(y);
	queue<int>q;vis[1]=0;
	for(q.push(1);!q.empty();){
		x=q.front();q.pop();
		vector<int>&v=M[x];
		for(i=0;i<v.size();i++)if(vis[v[i]]==-1)vis[v[i]]=vis[x]+1,q.push(v[i]);
	}
	for(x=1;x<=n;x++)printf(x<n?"%d ":"%d\n",vis[x]);
}