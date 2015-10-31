#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define INF 99999999
using namespace std;

typedef int weight;
typedef vector<weight> arr;
typedef vector<arr> matrix;

weight OPT[(1 << 20)][40];
weight minimum_steiner_tree(const vector<int>& T, const matrix &g) {
  const int n = g.size();
  const int numT = T.size();
  if (numT <= 1) return 0;

  matrix d(g); // all-pair shortest
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

  for (int S = 0; S < (1 << numT); ++S)
    for (int x = 0; x < n; ++x)
      OPT[S][x] = INF;

  for (int p = 0; p < numT; ++p) // trivial case
    for (int q = 0; q < n; ++q)
      OPT[1 << p][q] = d[T[p]][q];

  for (int S = 1; S < (1 << numT); ++S) { // DP step
    if (!(S & (S-1))) continue;
    for (int p = 0; p < n; ++p)
      for (int E = 0; E < S; ++E)
        if ((E | S) == S)
          OPT[S][p] = min( OPT[S][p], OPT[E][p] + OPT[S-E][p] );
    for (int p = 0; p < n; ++p)
      for (int q = 0; q < n; ++q)
        OPT[S][p] = min( OPT[S][p], OPT[S][q] + d[p][q] );
  }
  weight ans = INF;
  for (int S = 0; S < (1 << numT); ++S)
    for (int q = 0; q < n; ++q)
      ans = min(ans, OPT[S][q] + OPT[((1 << numT)-1)-S][q]);
  return ans;
}

#define _M 99999
int parent[_M],rank[_M],a[_M],b[_M],flags[_M];
pair<int,int>node[_M];
int root(int a){return parent[a]==a?a:parent[a]=root(parent[a]);}
bool unite(int a,int b){
	int x=root(a),y=root(b);
	if(x==y)return false;
	if(::rank[x] < ::rank[y]){
		parent[x]=y;
	}else{
		parent[y]=x;
		if(::rank[x]==::rank[y])::rank[x]++;
	}
	return true;
}

int main(){
	int N,M,T;
	unordered_map<int,vector<pair<int,int>>>m;
	scanf("%d%d%d",&N,&M,&T);
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		m[a-1].emplace_back(b-1,c);
		m[b-1].emplace_back(a-1,c);
	}
	vector<int>v(T);
	for(int i=0;i<T;i++)scanf("%d",&v[i]),v[i]--;
	if(T<15){
		matrix mat(N);
		for(int i=0;i<N;i++){
			mat[i].assign(N,INF);
			mat[i][i]=0;
			for(auto &e:m[i])mat[i][e.first]=e.second;
		}
		printf("%d\n",minimum_steiner_tree(v,mat));
	}else{
		unordered_map<int,int> imp_back,notimp_back;
		vector<int>notimp;
		int c=0;
		sort(v.begin(),v.end());
		for(auto &e:v){
			imp_back.emplace(e,imp_back.size());
			for(;c!=e;c++){
				notimp.push_back(c);
				notimp_back.emplace(c,notimp_back.size());
			}
			c++;
		}
		for(;c<N;c++){
			notimp.push_back(c);
			notimp_back.emplace(c,notimp_back.size());
		}
		int l=notimp.size();

		int edges=0;
		for(int i=0;i<N;i++)for(auto &e:m[i]){
			a[edges]=i;
			b[edges]=e.first;
			node[edges].first=e.second;
			node[edges].second=edges;
			edges++;
		}
		sort(node,node+edges);
		for(int j=0;j<edges;j++){
			if(imp_back.find(a[node[j].second])!=imp_back.end())flags[j]|=1;
			if(imp_back.find(b[node[j].second])!=imp_back.end())flags[j]|=2;
		}

		int R=INF;
		//指数オーダー部分(この中の命令が少ないほど良い)
		for(int i=0;i<1<<l;i++){
			//unordered_map<int,int> points;//(imp_back);
			//for(int j=0;j<l;j++)if(i&(1<<j))points.emplace(notimp[j],points.size());
			for(int i=0;i<N;i++)parent[i]=i,::rank[i]=0;
			int r=0;
			int j=0;
			for(;j<edges;j++){
				int A=a[node[j].second],B=b[node[j].second];
				if(
					((flags[j]&1) || (i&(1<<notimp_back[A]))) /*points.find(A)!=points.end())*/ &&
					((flags[j]&2) || (i&(1<<notimp_back[B]))) /*points.find(B)!=points.end())*/
				){
					if(unite(A,B))r+=node[j].first;
					if(r>R)break;
				}
			}
			if(j==edges){
				int z=root(v[0]);
				bool f=true;
				//vだけ判定すれば良い
				for(auto &e:v)if(root(e)!=z){f=false;break;}
				if(f)R=r;
			}
		}
		printf("%d\n",R);
	}
}