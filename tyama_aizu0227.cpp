#include <cstdio>
#include <vector>
#include <algorithm>
int main(){
	int i,n,m,x;
	for(;scanf("%d%d",&n,&m),n;printf("%d\n",x)){
		std::vector<int>v;
		for(i=0;i<n;i++)scanf("%d",&x),v.push_back(x);
		std::sort(v.begin(),v.end());
		for(x=i=0;i<n;i++)x+=(i%m==n%m)?0:v[i];
	}
}