#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_V 6000
#define NOT(n) (((n)+V)%(V*2))
#define ADD(a,b) add_edge(NOT(a),b),add_edge(NOT(b),a)

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
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i;
	cin>>V;
	if(V>52*52){
		puts("Impossible");
		return 0;
	}
	vector<string>v(V);
	for(int i=0;i<V;i++)cin>>v[i];
	for(int i=0;i<V;i++)for(int j=i+1;j<V;j++){
		if(v[i][0]==v[j][0] || (v[i][1]==v[j][1]&&v[i][2]==v[j][2]))ADD(NOT(i),NOT(j));
		if(v[i][0]==v[j][2] || (v[i][1]==v[j][0]&&v[i][2]==v[j][1]))ADD(NOT(i),j);
		if((v[i][0]==v[j][1]&&v[i][1]==v[j][2]) || v[i][2]==v[j][0])ADD(i,NOT(j));

		if((v[i][0]==v[j][0]&&v[i][1]==v[j][1]) || v[i][2]==v[j][2])ADD(i,j);
	}
	V*=2;
	scc();
	V/=2;
	for(i=0;i<V;i++)if(cmp[i]==cmp[i+V])break;
	if(i<V)puts("Impossible");
	else for(i=0;i<V;i++){
		if(cmp[i]>cmp[i+V]){
			printf("%c %c%c\n",v[i][0],v[i][1],v[i][2]);
		}else{
			printf("%c%c %c\n",v[i][0],v[i][1],v[i][2]);
		}
	}
}
