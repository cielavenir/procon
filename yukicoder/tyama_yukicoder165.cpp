#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<pair<int,int>,int> ppiii;

int main(){
	int N,B,R=0;
	scanf("%d%d",&N,&B);
	vector<ppiii> v(N);
	for(int i=0;i<N;i++)scanf("%d%d%d",&v[i].first.first,&v[i].first.second,&v[i].second);
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++)for(int j=i;j<N;j++){
		if(
			((0<i&&v[i-1].first.first==v[i].first.first) || (j<N-1&&v[j].first.first==v[j+1].first.first))
		)continue;
		vector<pair<int,int> > z;
		for(int k=i;k<=j;k++)z.push_back(make_pair(v[k].first.second,v[k].second));
		sort(z.begin(),z.end());
		int start=0,prevend,end=0,point=0;
		for(;end<z.size();){
			for(;start<z.size()&&point>B;){
				point-=z[start++].second;
				for(;start<z.size()&&z[start-1].first==z[start].first;)point-=z[start++].second;
			}
			for(prevend=end;end<z.size()&&point<=B;){
				point+=z[end++].second;
				for(;end<z.size()&&z[end-1].first==z[end].first;)point+=z[end++].second;
				if(point<=B)prevend=end;
			}
			R=max(prevend-start,R);
		}
	}
	printf("%d\n",R);
}
/*
3 100
0 0 1
1 2 1
2 1 1
=> 3
*/