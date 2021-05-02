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

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

Graph opt; //optimal edges for minimum-spanning
vector<vector<int>> max_edge;
Weight minimumSpanningForest(const Graph &g) {
  int n = g.size();
  priority_queue<Edge> Q;
  for(int u=0;u<n;u++) for(auto &e: g[u]) /*if (u < e.dst)*/ Q.push(e);
  UnionFind uf(n);

  Weight total = 0;
  Edges F;
  while (F.size() < n-1 && !Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (uf.unionSet(e.src, e.dst)) {
      F.push_back(e);
      total += e.weight;
      opt[e.src].emplace_back(e.src,e.dst,e.weight);
      opt[e.dst].emplace_back(e.dst,e.src,e.weight);
    }
  }
  return total; //pair<Weight, Edges>(total, F);
}

void dfs(int z,int c,long long k,vector<int>&v){
	max_edge[z][c]=k;
	v[c]=1;
	for(auto &e:opt[c])if(!v[e.dst])dfs(z,e.dst,max(k,e.weight),v);
}

int main(){
	int N,M,Q,a,b,c;
	scanf("%d%d",&N,&M);
	opt.resize(N);
	Weight w;
	{
		Graph g(N);
		for(;M--;){
			scanf("%d%d%d",&a,&b,&c);
			g[a-1].emplace_back(a-1,b-1,c);
		}
		w=minimumSpanningForest(g);
	}
	max_edge.resize(N);
	for(int i=0;i<N;i++)max_edge[i].resize(N);
	for(int i=0;i<N;i++){
		vector<int>v(N);
		dfs(i,i,0,v);
	}
	scanf("%d",&Q);
	for(;Q--;){
		scanf("%d%d",&a,&b);
		printf("%lld\n",w-max_edge[a-1][b-1]);
	}
}
