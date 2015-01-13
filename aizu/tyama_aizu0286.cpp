#include <unordered_map>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
	int N,M,L;
	scanf("%d%d",&N,&M);
	unordered_map<long long,int>m;
	for(int s,t,e;scanf("%d%d%d",&s,&t,&e),s;)m[((long long)s<<32)|t]=e;
	for(scanf("%d",&L);L--;){
		vector<int>c(N);
		vector<int>b(M);
		for(int i=0;i<M;i++)scanf("%d",&b[i]);
		for(auto &e:m){
			int s=e.first>>32,t=e.first&0xffffffff,u=e.second;
			c[s-1]+=b[t-1]*u;
		}
		for(int i=0;i<N;i++)printf(i<N-1?"%d ":"%d\n",c[i]);
	}
}