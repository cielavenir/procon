#include <cstdio>
#include <vector>
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
	int i,V,E,start,goal,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d",&V,&E);
		scanf("%d%d",&start,&goal);start--,goal--;
		Graph g(V);
		for(;E--;)scanf("%d%d%d",&s,&t,&e),g[s-1].push_back(Edge(s-1,t-1,e)),g[t-1].push_back(Edge(t-1,s-1,e));
		vector<Weight> dist1,dist2;
		vector<int> prev;
		shortestPath(g,start,dist1,prev);
		prev.clear();
		shortestPath(g,goal,dist2,prev);
		for(i=0;i<V;i++){
			if(dist1[i]!=INF&&dist1[i]==dist2[i]){
				printf("%d\n",i+1);
				return 0;
			}
		}
		puts("-1");
	//}
}