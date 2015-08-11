#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int N;
	scanf("%d",&N);
	std::vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	std::sort(v.begin(),v.end());
	for(int i=0;i<N;i++)printf(i<N-1?"%d ":"%d\n",v[i]);
}