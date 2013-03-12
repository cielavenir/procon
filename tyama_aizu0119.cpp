#include <queue>
#include <cstdio>
using namespace std;
main(){
	int n,m,x,y;
	scanf("%d%d",&m,&n);
	vector<vector<int> >v(m+1);
	vector<int>c(m+1);
	queue<int>q;
	for(;n--;)scanf("%d%d",&x,&y),v[x].push_back(y),c[y]++;
	for(x=1;x<=m;x++)if(!c[x])q.push(x);
	for(;!q.empty();)for(printf("%d\n",n=q.front()),q.pop(),x=0;x<v[n].size();x++)if(--c[v[n][x]]==0)q.push(v[n][x]);
}