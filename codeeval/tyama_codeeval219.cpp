#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define INF 9999999

typedef int Weight;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

const int M = 20;
Weight best[1<<M][M];
int    prev[1<<M][M];
void buildPath(int S, int i, vector<int> &path) {
  if (!S) return;
  buildPath(S^(1<<i), ::prev[S][i], path);
  path.push_back(i);
}
Weight shortestHamiltonPath(const Matrix &w, vector<int> &path) {
  int n=w.size();
  int N = 1 << n;
  REP(S,N) REP(i,n) best[S][i] = INF;
  best[0][0] = 0;
  REP(S,N) REP(i,n) REP(j,n) if (!(S&(1<<j)))
    if (best[S|(1<<j)][j] > best[S][i] + w[i][j])
      best[S|(1<<j)][j] = best[S][i] + w[i][j],
      ::prev[S|(1<<j)][j] = i;
  int t = min_element(best[N-1], best[N-1]+n) - best[N-1];
  //path.clear(); buildPath(N-1, t, path);
  return best[N-1][t]==INF ? -1 : best[N-1][t];
}

int main(){
	string line,s;
	for(;getline(cin,line);){
		vector<tiii> v;
		map<int,int> m;
		{
			istringstream ss(line);
			int x,y,z;
			for(;ss>>x>>y>>z;ss>>s){
				v.emplace_back(x,y,z);
				if(m.find(x)==m.end())m.emplace(x,m.size());
				if(m.find(y)==m.end())m.emplace(y,m.size());
			}
		}
		int N=m.size();
		if(N>16){
			puts("False");
			continue;
		}
		Matrix w(N);
		for(int i=0;i<N;i++){
			w[i].resize(N);
			for(int j=0;j<N;j++)w[i][j]=(i!=j)*INF;
		}
		for(auto &e:v){
			w[m.at(get<0>(e))][m.at(get<1>(e))]=w[m.at(get<1>(e))][m.at(get<0>(e))]=get<2>(e);
		}
		vector<int> path;
		int r=shortestHamiltonPath(w,path);
		if(r!=-1){
			printf("%d\n",r);
		}else{
			puts("False");
		}
	}
}