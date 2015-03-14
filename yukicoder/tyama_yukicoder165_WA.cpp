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
		if(v[i].first.second<=v[j].first.second){
			int r=0,b=0;
			for(int k=0;k<N;k++)if(
				v[i].first.first<=v[k].first.first&&v[k].first.first<=v[j].first.first &&
				v[i].first.second<=v[k].first.second&&v[k].first.second<=v[j].first.second
			){
				r++;
				b+=v[k].second;
			}
			if(b<=B*100)R=max(R,r);
		}
		if(v[i].first.second>=v[j].first.second){
			int r=0,b=0;
			for(int k=0;k<N;k++)if(
				v[i].first.first<=v[k].first.first&&v[k].first.first<=v[j].first.first &&
				v[i].first.second>=v[k].first.second&&v[k].first.second>=v[j].first.second
			){
				r++;
				b+=v[k].second;
			}
			if(b<=B*100)R=max(R,r);
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