#include <map>
#include <vector>
#include <cstdio>
using namespace std;
map<int,vector<int> >M;
map<int,int>visit;
int D(int t,int a,int p,int d){
	int i=0,r=0;
	if(a!=p&&(r+=t==a&&d%2,!visit[a]))for(visit[a]=1;i<M[a].size();i++)r+=D(t,M[a][i],a,d+1);
	return r;
}
main(){
	int n,m,a,b,r;
	scanf("%d%d",&n,&m);
	for(;m;m--)scanf("%d%d",&a,&b),M[a].push_back(b),M[b].push_back(a);
	for(m=1;m<=n;m++)if(!visit[m])r+=D(m,m,0,0);
	printf("%d\n",r+(n-r)%2);
}