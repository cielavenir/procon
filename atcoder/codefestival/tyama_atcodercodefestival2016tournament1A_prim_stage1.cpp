#include <vector>
#include <queue>
#include <cstdio>
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

pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r1, int r2) {
  int n = g.size();
  Edges T;
  Weight total = 0;

  vector<bool> visited(n);
  priority_queue<Edge> Q;
  Q.push( Edge(-1, r1, 0) );
  Q.push( Edge(-1, r2, 0) );
  while (!Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (visited[e.dst]) continue;
    T.push_back(e);
    total += e.weight;
    visited[e.dst] = true;
    for(auto &f: g[e.dst]) if (!visited[f.dst]) Q.push(f);
  }
  return pair<Weight, Edges>(total, T);
}

int main(){
	int N,M,Q,a,b,c;
	scanf("%d%d",&N,&M);
	Graph g(N);
	for(;M--;){
		scanf("%d%d%d",&a,&b,&c);
		g[a-1].emplace_back(a-1,b-1,c);
		g[b-1].emplace_back(b-1,a-1,c);
	}
	scanf("%d",&Q);
	if(Q>3000)return 1;
	for(;Q--;){
		scanf("%d%d",&a,&b);
		printf("%lld\n",minimumSpanningTree(g,a-1,b-1).first);
	}
}
