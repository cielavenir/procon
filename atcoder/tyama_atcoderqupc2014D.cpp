#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF (1<<30)-1

#define D(d) (d==INF?INF:(--upper_bound(v.begin(),v.end(),make_pair(d,INF)))->second)

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
    FOR(f,g[e.dst]) {
      if (dist[f->dst] > e.weight+f->weight) {
        dist[f->dst] = e.weight+f->weight;
        Q.push(Edge(f->src, f->dst, e.weight+f->weight));
      }
    }
  }
}

int main(){
	int n,m,k,s,g,a,b,d;
	scanf("%d%d%d%d%d",&n,&m,&k,&s,&g);
	vector<Weight> dist1,dist2;
	{
		vector<int> prev1,prev2;
		Graph G(n);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&d);
			G[a].push_back(Edge(a,b,d));
			G[b].push_back(Edge(b,a,d));
		}
		shortestPath(G,s,dist1,prev1);
		shortestPath(G,g,dist2,prev2);
	}
	vector<pair<int,int> >v(k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&a,&b);
		v[i]=make_pair(a,b);
	}
	d=D(dist1[g]);
	for(int i=0;i<n;i++)d=min(d,D(dist1[i])+D(dist2[i]));
	printf("%d\n",d);
}