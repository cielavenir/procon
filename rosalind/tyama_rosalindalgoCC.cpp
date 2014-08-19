#include <vector>
#include <map>
#include <cstdio>
using namespace std;
map<int,vector<int> >M;
int vis[1001];
void D(int n){
	vis[n]=1;
	int i=0;
	vector<int>&v=M[n];
	for(;i<v.size();i++)if(!vis[v[i]])D(v[i]);
}
int main(){
	int n,m,x,y,i=0;
	for(scanf("%d%d",&n,&m);i<m;i++)scanf("%d%d",&x,&y),M[x].push_back(y),M[y].push_back(x);
	for(y=0,x=1;x<=n;x++)if(!vis[x])D(x),y++;
	printf("%d\n",y);
}