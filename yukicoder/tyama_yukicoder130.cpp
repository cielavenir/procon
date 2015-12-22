#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int dfs(int d,const vector<int> &_v){
	if(_v.size()<2)return 0;
	vector<vector<int> > v(2);
	for(auto &e:_v){
		int x=e&(1<<d);
		v[x>>d].push_back(e^x);
	}
	return v[0].empty()?dfs(d-1,v[1]):v[1].empty()?dfs(d-1,v[0]):(1<<d)+min(dfs(d-1,v[0]),dfs(d-1,v[1]));
}

int main(){
	int N;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	printf("%d\n",dfs(29,v));
}