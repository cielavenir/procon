#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 99999999

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
	int N,V,X,Y;
	scanf("%d%d%d%d",&N,&V,&X,&Y);X--,Y--;
	vector<vector<int> >v(N);
	for(int i=0;i<N;i++){
		v[i].resize(N);
		for(int j=0;j<N;j++)scanf("%d",&v[i][j]);
	}

	///
	int H=N,W=N;
	Graph g(H*W);
	for(int i=0;i<H;i++)for(int j=0;j<W;j++){
		int x=i*W+j,y,f;
		if(i<H-1){
			y=(i+1)*W+j;
			f=v[i][j]-v[i+1][j];
			g[x].push_back(Edge(x,y,v[i+1][j])),g[y].push_back(Edge(y,x,v[i][j]));
		}
		if(j<W-1){
			y=i*W+j+1;
			f=v[i][j]-v[i][j+1];
			g[x].push_back(Edge(x,y,v[i][j+1])),g[y].push_back(Edge(y,x,v[i][j]));
		}
	}
	///

	vector<Weight>dist;
	vector<int>prev;
	shortestPath(g,0,dist,prev);
	if(dist[N*N-1]>=V){
		int o;
		if(X<0||Y<0||(o=dist[Y*W+X])>=V||(shortestPath(g,Y*W+X,dist,prev),dist[N*N-1]>=2*(V-o))){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}