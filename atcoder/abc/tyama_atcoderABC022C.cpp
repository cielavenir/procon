#include <vector>
#include <cstdio>
using namespace std;

int main(){
	const int INF=1<<29;
	int N,M;
	scanf("%d%d",&N,&M);
	vector<vector<int> >G(N);
	for(int i=0;i<N;i++){
		G[i].resize(N);
		for(int j=0;j<N;j++)G[i][j]=(i!=j)*INF;
	}
	for(int i=0;i<M;i++){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		u--;
		v--;
		G[u][v]=G[v][u]=l;
	}
	vector<int>v;
	for(int i=1;i<N;i++)if(G[0][i]<INF)v.push_back(i);
	for(int k=1;k<N;k++)for(int i=1;i<N;i++)for(int j=1;j<N;j++){
		if(G[i][j]>G[i][k]+G[k][j])G[i][j]=G[i][k]+G[k][j];
	}
	int r=INF;
	for(int i=0;i<v.size();i++)for(int j=i+1;j<v.size();j++){
		if(r>G[0][v[i]]+G[v[i]][v[j]]+G[v[j]][0])r=G[0][v[i]]+G[v[i]][v[j]]+G[v[j]][0];
	}
	printf("%d\n",r==INF?-1:r);
}