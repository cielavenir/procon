#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<vector<int> > Graph;

#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)
void visit(int v, const Graph &g,
    vector<int> &ord, vector<int> &num, int k) {
  if (num[v] >= 0) return;
  num[v] = k;
  for (int i = 0; i < g[v].size(); ++i)
    visit(g[v][i], g, ord, num, k);
  ord.push_back(v);
}
typedef pair<int,int> clause;
void two_satisfiability(int m, const vector<clause> &cs, vector<int> &num) {
  int n = m * 2; // m positive vars and m negative vars
  Graph g(n), h(n);
  for (int i = 0; i < cs.size(); ++i) {
    int u = cs[i].first, v = cs[i].second;
    g[NOT(u)].push_back( v );
    g[NOT(v)].push_back( u );
    h[v].push_back( NOT(u) );
    h[u].push_back( NOT(v) );
  }
  vector<int> ord, dro;
  num.resize(n);
  fill(num.begin(),num.end(),-1);
  for (int i = 0; i < n; ++i)
    visit(i, g, ord, num, i);
  reverse(ord.begin(), ord.end());
  fill(num.begin(), num.end(), -1);
  for (int i = 0; i < n; ++i)
    visit(ord[i], h, dro, num, i);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,i;
	cin>>N;
	if(N>52*52){
		puts("Impossible");
		return 0;
	}
	vector<string>v(N);
	for(int i=0;i<N;i++)cin>>v[i];
	vector<clause>cs;
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
		if(v[i][0]==v[j][0] || (v[i][1]==v[j][1]&&v[i][2]==v[j][2]))cs.emplace_back(NOT(VAR(i)),NOT(VAR(j)));
		if(v[i][0]==v[j][2] || (v[i][1]==v[j][0]&&v[i][2]==v[j][1]))cs.emplace_back(NOT(VAR(i)),VAR(j));
		if((v[i][0]==v[j][1]&&v[i][1]==v[j][2]) || v[i][2]==v[j][0])cs.emplace_back(VAR(i),NOT(VAR(j)));

		if((v[i][0]==v[j][0]&&v[i][1]==v[j][1]) || v[i][2]==v[j][2])cs.emplace_back(VAR(i),VAR(j));
	}
	vector<int>num;
	two_satisfiability(N,cs,num);
	for(i=0;i<N;i++)if(num[VAR(i)]==num[NOT(VAR(i))])break;
	if(i<N)puts("Impossible");
	else for(i=0;i<N;i++){
		if(num[VAR(i)]>num[NOT(VAR(i))]){
			printf("%c %c%c\n",v[i][0],v[i][1],v[i][2]);
		}else{
			printf("%c%c %c\n",v[i][0],v[i][1],v[i][2]);
		}
	}
}
