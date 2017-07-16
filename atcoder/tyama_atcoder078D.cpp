#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 99999999

typedef int Weight;
typedef vector<Weight> Array;
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
typedef unordered_map<int,Edges> Graph;

void shortestPath(Graph &g, int s,
    Array &dist, Array &prev) {
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
	int i,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d",&V);
		Graph g(V);
		for(i=0;i<V-1;i++)scanf("%d%d",&s,&t),g[s-1].push_back(Edge(s-1,t-1,1)),g[t-1].push_back(Edge(t-1,s-1,1));
		Array dist1(V),dist2(V),prev(V);
		shortestPath(g,0,dist1,prev);
		shortestPath(g,V-1,dist2,prev);
		int r=0;
		for(i=0;i<V;i++)r+=dist1[i]>dist2[i];
		puts(r<V-r ? "Fennec" : "Snuke");
	//}
}
