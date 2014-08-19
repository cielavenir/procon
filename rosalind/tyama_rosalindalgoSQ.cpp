#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
map<int,vector<int> >M;
int vis[1001];
int D(int n,int d){
	vis[n]=d;
	int i=0;
	vector<int>&v=M[n];
	for(;i<v.size();i++){
		if(vis[v[i]]){
			if(vis[v[i]]==d-3)return 1;
		}else if(D(v[i],d+1)==1)return 1;
	}
	return -1;
}
int main(){
	int T,n,m,x,y,i,s;
	for(scanf("%d",&T);T;T--){
		M.clear();
		memset(vis,0,sizeof(vis));
		for(scanf("%d%d",&n,&m),i=0;i<m;i++){
			scanf("%d%d",&x,&y),M[x].push_back(y),M[y].push_back(x);
			if(i==0)s=x;
		}
		printf(T>1?"%d ":"%d\n",D(s,1));
	}
}