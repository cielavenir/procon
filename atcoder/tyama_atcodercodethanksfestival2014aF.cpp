#include <vector>
#include <set>
#include <cstdio>
using namespace std;

set<int> se;
void dfs(int cur,const vector<vector<int> >&v){
	for(int i=0;i<v[cur].size();i++){
		dfs(v[cur][i],v);
		se.insert(v[cur][i]);
	}
}

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<vector<int> >v(N);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[b-1].push_back(a-1);
	}
	dfs(0,v);
	printf("%d\n",se.size()+1);
}