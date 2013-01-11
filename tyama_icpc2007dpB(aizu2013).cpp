#include<vector>
#include<cstdio>
#include<algorithm>
main(){
	int N,i,h,m,d;
	for(;scanf("%d",&N),N;printf("%d\n",m)){
		std::vector<pair<int,int> >v;
		for(i=0;i<N*2;i++)scanf("%d:%d:%d",&h,&m,&d),v.push_back(std::make_pair(h*3600+m*60+d,i%2?-1:1));
		std::sort(v.begin(),v.end());
		for(h=m=i=0;i<N*2;i++)h+=v[i].second,m=max(m,h);
	}
}