#include<cstdio>
#include<vector>
#include<algorithm>
main(){
	for(int Q,L,q,x;scanf("%d%d",&Q,&L),Q;puts("end"))
		for(std::vector<int>v;Q--;){
			if(v.size()>L)v.erase(v.begin());
			if(scanf("%d%d",&q,&x),!q)v.push_back(x);
			if(q==1)v.erase(v.begin()+x-1);
			if(q==2)printf("%d\n",v[x-1]);
			if(q==3)v.erase(std::find(v.begin(),v.end(),x));
		}
}