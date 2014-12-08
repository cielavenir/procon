#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
set<int>result;
set<pair<int,int> >memo;

void dfs(/*const*/ vector<map<int,vector<int> > >&v,const vector<int> &d,int cur,int depth){
	if(depth==d.size()){
		result.insert(cur+1);
	}else{
		pair<int,int> x=make_pair(cur,depth);
		if(memo.find(x)!=memo.end())return;
		for(auto &it:v[cur][d[depth]]){
			dfs(v,d,it,depth+1);
		}
		memo.insert(x);
	}
}

int main(){
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	vector<map<int,vector<int> > >v(N);
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a-1][c].push_back(b-1);
		v[b-1][c].push_back(a-1);
	}
	vector<int>d(K);
	for(int i=0;i<K;i++)scanf("%d",&d[i]);
	for(int i=0;i<N;i++)dfs(v,d,i,0);
	printf("%d\n",result.size());
	bool f=false;
	for(auto &it:result){
		if(f)putchar(' ');
		f=true;
		printf("%d",it);
	}
	puts("");
}