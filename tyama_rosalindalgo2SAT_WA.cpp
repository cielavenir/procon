#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define NEG(a) ((a)<V?(a)+V:(a)-V)
using namespace std;

//typedef vector<vector<int> > Graph;
typedef map<int,vector<int> > Graph;

void visit(Graph &g, int v, vector< vector<int> >& scc,
    stack<int> &S, map<int,bool> &inS,
    map<int,int> &low, map<int,int> &num, int& time) {
  low[v] = num[v] = ++time;
  S.push(v); inS[v] = true;
  FOR(e, g[v]) {
    int w = *e/*->dst*/;
    if (num[w] == 0) {
      visit(g, w, scc, S, inS, low, num, time);
      low[v] = min(low[v], low[w]);
    } else if (inS[w])
      low[v] = min(low[v], num[w]);
  }
  if (low[v] == num[v]) {
    scc.push_back(vector<int>());
    while (1) {
      int w = S.top(); S.pop(); inS[w] = false;
      scc.back().push_back(w);
      if (v == w) break;
    }
  }
}
void stronglyConnectedComponents(Graph& g,
    vector< vector<int> >& scc) {
  //const int n = g.size();
  //vector<int> num(n), low(n);
  map<int,int> num,low;
  stack<int> S;
  //vector<bool> inS(n);
  map<int,bool>inS;
  int time = 0;
  FOR(u, g) if (num[u->first] == 0)
    visit(g, u->first, scc, S, inS, low, num, time);
}

int main(){
	int K,i,j,k,V,E,s,t;
	for(scanf("%d",&K);K;--K){
		scanf("%d%d",&V,&E);
		Graph g;//(2*V);
		for(;E--;){
			scanf("%d%d",&s,&t);
			if(s>0)s--;else s=V-s-1;
			if(t>0)t--;else t=V-t-1;
			//printf("---%d %d\n",NEG(s),t);
			//printf("---%d %d\n",NEG(t),s);
			g[NEG(s)].push_back(t);
			g[NEG(t)].push_back(s);
		}
		map<int,int>m;
		for(;;){
			vector< vector<int> > scc;
			stronglyConnectedComponents(g,scc);
			//printf("+++%d\n",g.size());
			for(i=0;i<scc.size();i++){
				for(j=0;j<scc[i].size();j++){
					for(k=j+1;k<scc[i].size();k++)if(scc[i][j]==NEG(scc[i][k]))goto fail;
				}
				s=scc[i].back();
				//printf("%d\n",s);
				if(m.find(s+1)==m.end()&&m.find(s-V+1)==m.end())
					if(s<V)m[s+1]=1;else m[s-V+1]=-1;
				//kill graph
				if(g.find(s)!=g.end())g[s].clear();
				if(g.find(NEG(s))!=g.end())g[NEG(s)].clear();
				for(j=2*V-1;j>=0;j--){
					if(g.find(j)==g.end())continue;
					remove(g[j].begin(),g[j].end(),s);
					remove(g[j].begin(),g[j].end(),NEG(s));
					if(g[j].empty())g.erase(j);
				}
			}
			if(g.size()==0)break;
		}

		printf("1");
		for(map<int,int>::iterator it=m.begin();it!=m.end();it++)printf(" %d",it->first*it->second);
		puts("");
		continue;
fail:
		puts("0");
	}
}