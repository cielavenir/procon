#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX_V 10000

int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];
void add_edge(int from, int to){
	G[from].push_back(to); rG[to].push_back(from);
}
void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		if (!used[G[v][i]]) dfs(G[v][i]);
	}
	vs.push_back(v);
}
void rdfs(int v, int k) {
	used[v] = true;
	cmp[v] = k;
	for (int i = 0; i < rG[v].size(); i++) {
		if (!used[rG[v][i]]) rdfs(rG[v][i], k);
	}
}
int scc() {
	memset(used, 0, sizeof(used)); vs.clear();
	for (int v = 0; v < V; v++) {
		if (!used[v]) dfs(v);
	}
	memset(used, 0, sizeof(used));
	int k = 0;
	for (int i = vs.size() - 1; i >= 0; i--) {
		if (!used[vs[i]]) rdfs(vs[i], k++);
	}
	return k;
}

int main(){
	int T,i,E,s,t;
	for(scanf("%d",&T);T--;){
		for(auto &e:G)e.clear();
		for(auto &e:rG)e.clear();
		scanf("%d%d",&V,&E);
		for(;E--;){
			scanf("%d%d",&s,&t);
			if(s<0)s=-s+V;
			if(t<0)t=-t+V;
			s--,t--;
			add_edge((s+V)%(V*2),t);
			add_edge((t+V)%(V*2),s);
		}
		V*=2;
		scc();
		V/=2;
		for(i=0;i<V;i++)if(cmp[i]==cmp[i+V])break;
		if(i<V)puts("0");
		else{
			printf("1");
			for(i=0;i<V;i++)printf(" %d",cmp[i]>cmp[i+V] ? i+1 : -i-1);
			puts("");
		}
	}
}
