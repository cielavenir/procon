#include <cstdio>
#include <vector>
#include <queue>
#define INF 1LL<<60
using namespace std;

typedef long long Weight;
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
	int i,V,E,start,goal,s,t,e,f;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d",&V,&E);
		scanf("%d%d",&start,&goal);start--,goal--;
		Graph g(V),h(V);
		for(;E--;){
			scanf("%d%d%d%d",&s,&t,&e,&f);
			g[s-1].push_back(Edge(s-1,t-1,e)),g[t-1].push_back(Edge(t-1,s-1,e));
			h[s-1].push_back(Edge(s-1,t-1,f)),h[t-1].push_back(Edge(t-1,s-1,f));
		}
		vector<Weight> dist1,dist2;
		vector<int> prev;
		shortestPath(g,start,dist1,prev);
		prev.clear();
		shortestPath(h,goal,dist2,prev);
		vector<long long>r(V+1);
		for(i=V-1;i>=0;i--)r[i]=max(r[i+1],1000000000000000LL-dist1[i]-dist2[i]);
		for(i=0;i<V;i++)printf("%lld\n",r[i]);
	//}
}
