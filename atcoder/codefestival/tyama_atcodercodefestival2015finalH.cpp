#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
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

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	Graph G(M+1);
	vector<Weight> dist;
	vector<int> prev;
	for(int i=0;i<M;i++){
		G[i].push_back(Edge(i,i+1,2));
		G[i+1].push_back(Edge(i+1,i,0));
	}
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(Edge(x,x+y,y));
	}
	shortestPath(G,0,dist,prev);
	printf("%d\n",2*M-dist[M]);
}