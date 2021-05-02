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

Weight minimumSpanningForest(const Graph &g) {
  int n = g.size();
  priority_queue<Edge> Q;
  for(int u=0;u<n;u++) for(auto &e: g[u]) if (u < e.dst) Q.push(e);
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
  return total; //pair<Weight, Edges>(total, F);
}

int main(){
	int N,M,a,b,c;
	scanf("%d%d",&N,&M);
	Graph G(N);
	vector<int>C(N,1<<30);
	for(;M--;){
		scanf("%d%d%d",&a,&b,&c);
		G[a].emplace_back(a,b,c);
		G[b].emplace_back(b,a,c);
		C[a]=min(C[a],c+1);
		C[b]=min(C[b],c+2);
	}
	for(int i=0;i<2*N;i++)C[(i+1)%N]=min(C[(i+1)%N],C[i%N]+2);
	for(int i=0;i<N;i++){
		G[i].emplace_back(i,(i+1)%N,C[i]);
		G[(i+1)%N].emplace_back((i+1)%N,i,C[i]);
	}
	printf("%lld\n",minimumSpanningForest(G));
}
