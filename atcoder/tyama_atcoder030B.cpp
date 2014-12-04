#include <vector>
#include <cstdio>
using namespace std;

int dfs(const vector<int> &h,const vector<vector<int> >&m,int N,int cur,int prev){
	int ret=0;
	for(int i=0;i<N;i++)if(m[cur][i]&&i!=prev){
		ret+=dfs(h,m,N,i,cur);
	}
	if(prev>=0)ret+=(h[cur]|!!ret)*2;
	return ret;
}

int main(){
	int N,X;
	scanf("%d%d",&N,&X);X--;
	vector<int>h(N);
	vector<vector<int> >m(N);
	for(int i=0;i<N;i++){
		scanf("%d",&h[i]);
		m[i].resize(N);
	}
	h[X]=0;
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		m[a][b]=m[b][a]=1;
	}
	printf("%d\n",dfs(h,m,N,X,-1));
}