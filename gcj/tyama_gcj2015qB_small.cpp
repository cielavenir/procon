#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int dfs(vector<int> &_v){
	int front=_v.front();
	if(front<=3)return front;
	auto v=_v;
	for(int i=0;i<v.size();i++)v[i]--;
	int ret=dfs(v)+1;
	for(int i=2;i<=front-i;i++){
		v=_v;
		pop_heap(v.begin(),v.end()),v.pop_back();
		v.push_back(i),push_heap(v.begin(),v.end());
		v.push_back(front-i),push_heap(v.begin(),v.end());
		int r=dfs(v)+1;
		if(ret>r)ret=r;
	}
	return ret;
}

int main(){
	int t=1,T,N;
	for(scanf("%d",&T);t<=T;){
		fprintf(stderr,"[%d]\n",t);
		scanf("%d",&N);
		vector<int>v(N);
		for(int i=0;i<v.size();i++)scanf("%d",&v[i]);
		make_heap(v.begin(),v.end());
		printf("Case #%d: %d\n",t++,dfs(v));
	}
}