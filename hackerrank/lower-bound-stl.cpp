#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int N;
	scanf("%d",&N);
	std::vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	int T,x;
	for(scanf("%d",&T);T--;){
		scanf("%d",&x);
		auto it=lower_bound(v.begin(),v.end(),x);
		printf(*it==x?"Yes %d\n":"No %d\n",distance(v.begin(),it)+1);
	}
}