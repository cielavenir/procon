#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define INF (1LL<<60)
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
	int N,M,T;
	scanf("%d%d%d",&N,&M,&T);
	vector<long long>A(N);
	for(int i=0;i<N;i++)scanf("%lld",&A[i]);
	Graph G(N),F(N);
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);a--;b--;
		G[a].push_back(Edge(a,b,c));
		F[b].push_back(Edge(b,a,c));
	}
	vector<Weight> dist1,dist2;
	vector<int> prev;
	shortestPath(G,0,dist1,prev);
	shortestPath(F,0,dist2,prev);
	long long r=0;
	for(int i=0;i<N;i++)if(dist1[i]<INF && dist2[i]<INF)r=max(r,A[i]*(T-dist1[i]-dist2[i]));
	printf("%lld\n",r);
}