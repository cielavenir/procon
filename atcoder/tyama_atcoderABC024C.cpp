#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int N,D,K;
	scanf("%d%d%d",&N,&D,&K);
	std::vector<std::pair<int,int> >v(D);
	for(int i=0;i<D;i++)scanf("%d%d",&v[i].first,&v[i].second);
	for(;K--;){
		int S,T;
		scanf("%d%d",&S,&T);
		int mi=S,ma=S,i=0;
		for(;i<D&&(T<mi||ma<T);i++){
			int a=v[i].first,b=v[i].second;
			if(!(b<mi||ma<a)){
				mi=std::min(mi,a);
				ma=std::max(ma,b);
			}
		}
		printf("%d\n",i);
	}
}
