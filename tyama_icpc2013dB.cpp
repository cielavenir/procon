#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
main(){
	int M,T,P,R,m,t,p,j,ac,time;
	for(;scanf("%d%d%d%d",&M,&T,&P,&R),M;puts("")){
		map<int,pair< //team number
			map<int,int>, //problem, accepted_time
			map<int,int>  //problem, wrong_answer
		> >contest;
		for(;R--;){
			scanf("%d%d%d%d",&m,&t,&p,&j);
			if(j){ //wrong_answer
				contest[t].second[p]+=20;
			}else{
				contest[t].first[p]=m;
			}
		}
		vector<pair<pair<int,int>,int> >contestants;
		for(t=1;t<=T;t++){
			ac=time=0;
			map<int,int>::iterator it=contest[t].first.begin();
			for(;it!=contest[t].first.end();it++){
				ac++;
				time+=it->second+contest[t].second[it->first];
			}
			contestants.push_back(make_pair(make_pair(-ac,time),-t));
		}
		sort(contestants.begin(),contestants.end());
		printf("%d",-contestants[0].second);
		for(t=1;t<T;t++){
			printf(
				contestants[t].first.first==contestants[t-1].first.first &&
				contestants[t].first.second==contestants[t-1].first.second ? "=%d" : ",%d",
				-contestants[t].second
			);
		}
	}
}