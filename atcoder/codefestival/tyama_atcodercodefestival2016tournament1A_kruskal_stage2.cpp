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

pair<Weight, Edges> minimumSpanningForest2(priority_queue<Edge> &Q, int n) {
  UnionFind uf(n);

  Weight total = 0;
  Edges F;
  while (F.size() < n-1 && !Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (uf.unionSet(e.src, e.dst)) {
      F.push_back(e);
      total += e.weight;
    }
  }
  return pair<Weight, Edges>(total, F);
}

pair<Weight, Edges> minimumSpanningForest(const Graph &g) {
  int n = g.size();
  priority_queue<Edge> Q;
  for(int u=0;u<n;u++) for(auto &e: g[u]) if (u < e.dst) Q.push(e);
  return minimumSpanningForest2(Q,n);
}
pair<Weight, Edges> minimumSpanningForest(const Edges &g, int n) {
  priority_queue<Edge> Q;
  for(auto &e: g) Q.push(e);
  return minimumSpanningForest2(Q,n);
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
	pair<Weight, Edges> v=minimumSpanningForest(g);
	scanf("%d",&Q);
	if(Q>3000)return 1;
	for(;Q--;){
		scanf("%d%d",&a,&b);
		v.second.emplace_back(a-1,b-1,0);
		printf("%lld\n",minimumSpanningForest(v.second,N).first);
		v.second.pop_back();
	}
}
