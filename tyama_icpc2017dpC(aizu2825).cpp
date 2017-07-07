#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N,M,s,k,c;
	for(;~scanf("%d%d",&N,&M)&&N&&M;){
		vector<pair<int,int> >ma(N),mi(N);
		for(int i=0;i<N;i++)ma[i].second=mi[i].second=i;
		for(int i=0;i<M;i++){
			scanf("%d%d",&s,&k);
			for(int j=0;j<k;j++){
				scanf("%d",&c),c--;
				if(k==1)mi[c].first+=s;
				ma[c].first+=s;
			}
		}
		sort(ma.begin(),ma.end());
		sort(mi.begin(),mi.end());
		int r=0;
		for(int i=N-2;i<N;i++)for(int j=0;j<2;j++){
			if(ma[i].second!=mi[j].second)r=max(r,ma[i].first-mi[j].first);
		}
		printf("%d\n",r+1);
	}
}
