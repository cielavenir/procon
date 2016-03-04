#include <iostream>
#include <string>
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
	int H,W,start,goal;
	cin>>H>>W;
	Graph g(H*W);
	vector<string>v(H);
	for(int i=0;i<H;i++)cin>>v[i];
	for(int i=0;i<H;i++)for(int j=0;j<W;j++){
		int x=i*W+j,y,f;
		if(v[i][j]=='S')start=x;
		if(v[i][j]=='G')goal=x;
		if(i<H-1){
			y=(i+1)*W+j;
			if(v[i][j]!='#')g[x].push_back(Edge(x,y,1));
			if(v[i+1][j]!='#')g[y].push_back(Edge(y,x,1));
		}
		if(j<W-1){
			y=i*W+j+1;
			if(v[i][j]!='#')g[x].push_back(Edge(x,y,1));
			if(v[i][j+1]!='#')g[y].push_back(Edge(y,x,1));
		}
	}
	vector<Weight> dist1,dist2;
	vector<int> prev;
	shortestPath(g,start,dist1,prev);
	prev.clear();
	shortestPath(g,goal,dist2,prev);
	int r=0;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++){
		int x=i*W+j;
		if(v[i][j]=='#'&&dist1[x]!=INF&&dist2[x]!=INF)r=max(r,dist1[x]+dist2[x]);
	}
	printf("%d\n",r);
}