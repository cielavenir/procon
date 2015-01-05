#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int T,N,K;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&N,&K);
		vector<int>v(N);
		for(int i=0;i<N;i++)scanf("%d",&v[i]);
		vector<int>bag(K+1);
		bag[0]=1;
		for(int i=0;i<N;i++)for(int j=v[i];j<=K;j++)bag[j]+=bag[j-v[i]];
		int j=K;
		for(;j>0&&!bag[j];j--);
		printf("%d\n",j);
	}
}