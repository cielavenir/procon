#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
int main(){
	std::vector<int>odd;
	int T,N,t,n,x=0,y=0,z;
	scanf("%d",&T);
	for(t=0;t<T;t++){
		scanf("%d",&N);
		for(n=0;n<N/2;n++)scanf("%d",&z),x+=z;
		if(N%2)scanf("%d",&z),x+=z,y+=z,odd.push_back(z),n++;
		for(;n<N;n++)scanf("%d",&z),y+=z;
	}
	std::sort(odd.begin(),odd.end(),std::greater<int>());
	for(t=0;t<odd.size();t++)if(t&1)x-=odd[t];else y-=odd[t];
	printf("%d %d\n",x,y);
}