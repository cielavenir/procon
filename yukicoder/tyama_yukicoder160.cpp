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
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

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
	int r,x,i,V,E,s,t,e;
	scanf("%d%d%d%d",&V,&E,&r,&x);
	Graph g(V);
	vector<Weight> dist;
	vector<int> prev;
	for(;E--;)scanf("%d%d%d",&s,&t,&e),g[s].push_back(Edge(s,t,e)),g[t].push_back(Edge(t,s,e));
	shortestPath(g,x,dist,prev);
	for(printf("%d",r);r!=x;){
		int next=1<<29;
		for(auto &e:g[r]){
			if(dist[r]==dist[e.dst]+e.weight)next=min(next,e.dst);
		}
		r=next;
		printf(" %d",r);
	}
	puts("");
}