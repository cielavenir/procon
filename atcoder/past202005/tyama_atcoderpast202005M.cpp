#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#define INF 999999999
using namespace std;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void shortestPath(const Graph &g, int s,
    vector<Weight> &dist, vector<int> &prev) {
  int n = g.size();
  dist.assign(n, INF); dist[s] = 0;
  prev.assign(n, -1);
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if (prev[e.dst] != -1) continue;
    prev[e.dst] = e.src;
    for(auto &f:g[e.dst]) {
      if (dist[f.dst] > e.weight+f.weight) {
        dist[f.dst] = e.weight+f.weight;
        Q.push(Edge(f.src, f.dst, e.weight+f.weight));
      }
    }
  }
}

#define MA 20
int M[MA][MA];
int best[1<<MA][MA];
int prev[1<<MA][MA];
int shortestHamiltonPath(int st,int n) {
	int N = 1 << n;
	int S,i,j;
	for(S=0;S<N;S++)for(i=0;i<n;i++)best[S][i]=1<<29;
	best[1<<st][st]=0;
	for(S=0;S<N;S++)for(j=0;j<n;j++)if(!(S&(1<<j))){
		for(i=0;i<n;i++)if(best[S|(1<<j)][j] > best[S][i] + M[i][j]){
			best[S|(1<<j)][j] = best[S][i] + M[i][j];
			::prev[S|(1<<j)][j] = i;
		}
	}
	int t=1<<29;
	for(i=0;i<n;i++)if(t>best[N-1][i])t=best[N-1][i];
	return t;
}

int main(){
	int N,m;
	scanf("%d%d",&N,&m);
	Graph g(N);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
		g[u].push_back(Edge(u,v,1));
		g[v].push_back(Edge(v,u,1));
	}
	int s,k;
	scanf("%d%d",&s,&k);
	vector<int>v(k+1);v[0]=s-1;
	for(int i=0;i<k;i++){
		scanf("%d",&v[i+1]);v[i+1]--;
	}
	for(int i=0;i<k+1;i++){
		vector<Weight> dist;
		vector<int> prev;
		shortestPath(g,v[i],dist,prev);
		for(int j=0;j<k+1;j++){
			M[i][j]=dist[v[j]];
		}
	}
	printf("%d\n",shortestHamiltonPath(0,k+1));
}
