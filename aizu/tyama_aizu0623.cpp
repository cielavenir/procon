#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 1LL<<60

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
	int N,M,K,S,P,Q;
	scanf("%d%d%d%d%d%d",&N,&M,&K,&S,&P,&Q);
	unordered_map<int,int>depth;
	queue<int>q;
	for(int i=0;i<K;i++){
		int a;
		scanf("%d",&a);a--;
		depth[a]=0;
		q.push(a);
	}
	Graph g(N);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);a--,b--;
		g[a].push_back(Edge(a,b,b==N-1?0:depth.find(b)==depth.end()?P:INF));
		g[b].push_back(Edge(b,a,a==N-1?0:depth.find(a)==depth.end()?P:INF));
	}
	for(;!q.empty();){
		int cur=q.front();q.pop();
		if(depth[cur]==S)continue;
		for(auto &e:g[cur]){
			if(depth.find(e.dst)==depth.end()){
				depth[e.dst]=depth[cur]+1;
				q.push(e.dst);
			}
		}
	}
	for(int i=0;i<N;i++)for(auto &&e:g[i]){
		if(depth.find(e.dst)!=depth.end()&&e.weight==P)e.weight=Q;
	}
	vector<Weight>dist;
	vector<int>prev;
	shortestPath(g,0,dist,prev);
	printf("%lld\n",dist[N-1]);
}