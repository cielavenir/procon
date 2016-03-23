#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

map<int,int>memo;
int dfs(const vector<int>&v,int d){
	if(memo.find(d)!=memo.end())return memo[d];
	int r=0,d0=d;
	for(d++;d<v.size();d++)if(v[d0]%v[d]==0)r=max(r,dfs(v,d)+1);
	return memo[d0]=r;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end(),greater<int>());
	int r=0;
	for(int d=0;d<v.size();d++)r=max(r,dfs(v,d)+1);
	printf("%d\n",r);
}