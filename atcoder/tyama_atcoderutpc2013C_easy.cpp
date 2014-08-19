#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;

/*
typedef vector<vector<int> > Graph;
typedef pair<int, int> Result;
Result visit(int p, int v, const Graph &g) {
  Result r(0, v);
  FOR(e, g[v]) if (*e != p) {
    Result t = visit(v, *e, g);
    t.first++;
    if (r.first < t.first) r = t;
  }
  return r;
}
int diameter(const Graph &g) {
  Result r = visit(-1, 0, g);
  Result t = visit(-1, r.second, g);
  return t.first; // (r.second, t.second) is farthest pair
}
int main(){
	int N,M,n,m,a,b,i,j;
	scanf("%d%d",&N,&M);
	Graph g(N);
	for(i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	scanf("%d%d",&n,&m);
	g.resize(N+n);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		g[a+N].push_back(b+N);
		g[b+N].push_back(a+N);
	}
	int mi=1999999999,ma=0;
	for(i=0;i<N;i++)for(j=0;j<n;j++){
		g[i].push_back(j+N);
		g[j+N].push_back(i);
		int d=diameter(g);
		if(mi>d)mi=d;
		if(ma<d)ma=d;
		g[i].pop_back();
		g[j+N].pop_back();
	}
	printf("%d %d\n",mi,ma);
}
*/

pair<int,int> warshall(){
	int i,j,n,k,a,b,dist[1001][1001];
	scanf("%d%d",&n,&k);
	if(n>100)exit(1);
	/*initialize*/
	memset(dist,11,sizeof(dist));
	for(i=0;i<n;i++)dist[i][i]=0;
	for(;k;k--){
		scanf("%d%d",&a,&b);
		dist[a][b]=1,dist[b][a]=1;
	}

	{/*warshall-floyd*/
		int k,i,j;
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(dist[i][j]>dist[i][k]+dist[k][j])
						dist[i][j]=dist[i][k]+dist[k][j];
	}
	int mi=99999999,ma=0,m;
	for(i=0;i<n;i++){
		m=0;
		for(j=0;j<n;j++){
			if(m<dist[i][j])m=dist[i][j];
		}
		if(mi>m)mi=m;
		if(ma<m)ma=m;
	}
	return make_pair(mi,ma);
}
int main(){
	pair<int,int>p=warshall(),q=warshall();
	printf("%d %d\n",max(p.first+q.first+1,max(p.second,q.second)),p.second+q.second+1);
}