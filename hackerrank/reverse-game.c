//#include <vector>
//#include <algorithm>
//#include <numeric>
#include <stdio.h>
int main(){
	int T,N,K;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&N,&K);
		printf("%d\n",K<N/2 ? K*2+1 : N*2-K*2-2);
		/*
		std::vector<int>v(N);
		std::iota(v.begin(),v.end(),0);
		for(int i=0;i<N;i++)std::reverse(v.begin()+i,v.end());
		for(int i=0;i<N;i++)if(v[i]==K)printf("%d\n",i);
		*/
	}
}