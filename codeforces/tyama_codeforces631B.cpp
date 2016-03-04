#include <vector>
#include <set>
#include <cstdio>
using namespace std;

int main(){
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	vector<pair<int,int> >v(K);
	for(int i=0;i<K;i++){
		int c,r,a;
		scanf("%d%d%d",&c,&r,&a);
		if(c==1)v[i]=make_pair(r,a);
		else v[i]=make_pair(-r,a);
	}
	vector<bool>f(K);
	set<int>se;
	for(int i=K-1;i>=0;i--){
		if(se.find(v[i].first)==se.end()){
			se.insert(v[i].first);
			f[i]=true;
		}
	}
	vector<vector<int> >m(N);
	for(int i=0;i<N;i++)m[i].resize(M);
	for(int i=0;i<K;i++)if(f[i]){
		if(v[i].first>0){
			for(int j=0;j<M;j++)m[v[i].first-1][j]=v[i].second;
		}else{
			for(int j=0;j<N;j++)m[j][-v[i].first-1]=v[i].second;
		}
	}
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)printf(j<M-1 ? "%d ":"%d\n",m[i][j]);
}