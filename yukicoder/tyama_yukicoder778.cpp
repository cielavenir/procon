#include <vector>
#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<vector<int> >v;
deque<int>a;
long long dfs(int cur){
	auto it=lower_bound(a.begin(),a.end(),cur);
	int k=distance(a.begin(),it);
	long long r=k;
	a.insert(it,cur);
	for(auto &e:v[cur])r+=dfs(e);
	a.erase(a.begin()+k);
	return r;
}

int main(){
	int N,x;
	scanf("%d",&N);
	v.resize(N);
	for(int i=1;i<N;i++)scanf("%d",&x),v[x].push_back(i);
	printf("%lld\n",dfs(0));
}
