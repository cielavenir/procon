#include <cstdio>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 99999999
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
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

int M=INF;
void salesman(const Graph g,int s, int w,vector<int>path) {
	if(path.size()==g.size()){
		if(s==0&&M>w)M=w;
		return;
	}
	FOR(e,g[s])if(w+e->weight<M&&find(path.begin(),path.end(),e->dst)==path.end()){
		path.push_back(e->dst);
		salesman(g,e->dst,w+e->weight,path);
		path.pop_back();
	}
}

int main(){
	int T,V,E,s,t,e;
	//for(scanf("%d",&T);T;putchar(--T?' ':'\n')){
		scanf("%d%d",&V,&E);
		Graph g(V);
		for(;E--;)scanf("%d%d%d",&s,&t,&e),g[s].push_back(Edge(s,t,e));
		vector<int>path;
		salesman(g,0,0,path);
		printf("%d\n",M==INF?-1:M);
	//}
}