#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
main(){
	int t=1,T,n,N,S,p,x,y;
	for(scanf("%d",&T);t<=T;printf("Case #%d: %d\n",t++,n)){
		scanf("%d%d%d",&N,&S,&p);
		std::vector<int>v;
		for(n=0;n<N;n++)scanf("%d",&x),v.push_back(x);
		std::sort(v.begin(),v.end(),std::greater<int>());
		for(n=0;n<v.size();n++){
			x=p*3-2;y=p*3-4;
			if(p==1)y=x;
			if(v[n]>=x)continue;
			if(S&&v[n]>=y)S--;
			else break;
		}
	}
}