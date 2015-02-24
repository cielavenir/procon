#include <queue>
#include <set>
#include <cstdio>
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
const Weight INF=1<<29;

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
	int n;
	scanf("%d",&n);
	vector<int> input(n+1);
	vector<int> target(n+1);
	for(int i=1;i<=n;i++)scanf("%d",&input[i]);
	//build target point
	for(int i=1;i<=n;i++)if(!target[i]){
		set<int>lst;
		int cur=i;
		for(;input[cur];){
			if(lst.find(cur)!=lst.end()){
				for(auto &e:lst)target[e]=-1;
				break;
			}
			lst.insert(cur);
			cur+=input[cur];
		}
		if(!input[cur]){
			for(auto &e:lst)target[e]=cur;
			target[cur]=cur;
		}
	}
	//dijkstra
	Graph g(n+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=6;j++)if(i+j<=n&&~target[i+j])g[i].push_back(Edge(i,target[i+j],1));
	vector<Weight>dist;
	vector<int>prev;
	shortestPath(g,1,dist,prev);
	printf("%d\n",dist[n]);
}