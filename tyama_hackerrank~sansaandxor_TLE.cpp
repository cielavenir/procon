#include <vector>
#include <cstdio>
int main(){
	int T,N;
	for(scanf("%d",&T);T--;){
		scanf("%d",&N);
		std::vector<int>v(N);
		for(int i=0;i<N;i++)scanf("%d",&v[i]);
		int ret=0;
		for(int l=1;l<=N;l++){
			int val=0,i=0;
			for(;i<l;i++)val^=v[i];
			ret^=val;
			for(;i<N;i++)val^=v[i],val^=v[i-l],ret^=val;
		}
		printf("%d\n",ret);
	}
}