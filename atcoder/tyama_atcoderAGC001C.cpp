#include <vector>
#include <map>
#include <iostream>
using namespace std;
typedef vector<vector<int>> Graph;

void dfs(const Graph &g,vector<int>&v,int cur,int d){
	v[cur]=d;
	for(auto &e:g[cur])if(!v[e])dfs(g,v,e,d+1);
}

int main(){
	const int INF=1<<29;
	int N,K,R=INF;
	scanf("%d%d",&N,&K);
	Graph g(N);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(K%2==0){
		for(int i=0;i<N;i++){
			vector<int>v(N);
			v[i]=1;
			dfs(g,v,i,1);
			int r=0;
			for(int j=0;j<N;j++){
				if(v[j]-1>K/2)r++;
			}
			R=min(R,r);
		}
	}else{
		for(int i=0;i<N;i++)for(auto &k:g[i])if(i<k){
			vector<int>v(N);
			v[i]=v[k]=1;
			dfs(g,v,i,1);
			dfs(g,v,k,1);
			int r=0;
			for(int j=0;j<N;j++){
				if(v[j]-1>K/2)r++;
			}
			R=min(R,r);
		}
	}
	if(R==INF)return 1;
	printf("%d\n",R);
}