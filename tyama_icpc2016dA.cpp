#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int n;
	for(;scanf("%d",&n),n;){
		std::vector<int>v(n);
		for(int i=0;i<n;i++)scanf("%d",&v[i]);
		std::sort(v.begin(),v.end());
		int r=v[1]-v[0];
		for(int i=2;i<n;i++)r=std::min(r,v[i]-v[i-1]);
		printf("%d\n",r);
	}
}