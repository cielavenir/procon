#include <cstdio>
#include <queue>
#include <algorithm>

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define INF 2000000000000LL
using namespace std;

typedef long long Weight;
typedef pair<Weight,pair<int,int> >Edge;

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool shortestPath(Graph &g, Matrix &dist, vector<vector<int> > &prev){
	int n = g.size()-1;
	Array h(n+1);
	h.assign(n,INF);
	for(int k=0;k<n+1;k++)for(int i=0;i<n+1;i++)FOR(e,g[i]){
		if (h[e->second.first]<INF && e->first<INF && h[e->second.second] > h[e->second.first] + e->first){
			h[e->second.second] = h[e->second.first] + e->first;
			if(k==n)return false; // negative cycle
		}
	}
	for(int i=0;i<n;i++)FOR(e,g[i])e->first+=h[i]-h[e->second.second];
	dist.assign(n, Array(n,INF));
	prev.assign(n, vector<int>(n,-2));
	for(int s=0;s<n;s++){
		priority_queue<Edge> Q;
		Q.push(make_pair(0,make_pair(s,s)));
		for(;!Q.empty();){
			Edge e = Q.top(); Q.pop();
			if(prev[s][e.second.second]!=-2)continue;
			prev[s][e.second.second] = e.second.first;
			FOR(f,g[e.second.second]){
				if(-e.first<INF && f->first<INF && dist[s][f->second.second] > -e.first + f->first){
					dist[s][f->second.second] = -e.first + f->first;
					Q.push(make_pair(-(-e.first + f->first),make_pair(f->second.first, f->second.second)));
				}
			}
		}
		for(int u=0;u<n;u++){
			if(dist[s][u]<INF)dist[s][u] += h[u] - h[s];
		}
	}
	return true;
}

int main(){
	int r,T,V,E,s,t,e,i,j;
	scanf("%d%d",&V,&E);
	Graph g(V+1);
	Matrix dist;
	vector<vector<int> > prev;
	for(i=0;i<V;i++)g[i].push_back(make_pair(0,make_pair(i,i)));
	for(i=0;i<V;i++)g[V].push_back(make_pair(0,make_pair(V,i)));
	for(;E--;)scanf("%d%d%d",&s,&t,&e),g[s].push_back(make_pair(e,make_pair(s,t)));
	if(!shortestPath(g,dist,prev))puts("NEGATIVE CYCLE");
	else for(i=0;i<V;i++)for(j=0;j<V;j++){
		if(dist[i][j]>=INF)printf("INF");
		else printf("%lld",dist[i][j]);
		printf(j<V-1?" ":"\n");
	}
}