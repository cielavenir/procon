#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	vector<pair<pair<int,int>,int> >v(N);
	for(int i=0;i<N;i++)scanf("%d%d",&v[i].first.first,&v[i].first.second),v[i].second=i;
	sort(v.begin(),v.end());
	vector<int>result(N);
	for(int i=0;i<N;i++){
		//for(int j=i+1;j<N&&v[j].first.first<v[i].first.second;j++)result[v[i].second]++;
		auto it=lower_bound(v.begin(),v.end(),make_pair(make_pair(v[i].first.second,0),0));
		result[v[i].second]=distance(v.begin()+i,--it);
	}
	for(int i=0;i<N;i++)printf("%d\n",result[i]);
}