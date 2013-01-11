#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int n,d,i,r;
	for(;~scanf("%d%d",&n,&d);printf("%d\n",r)){
		std::vector<int>v;
		v.push_back(2),v.push_back(3);
		for(i=2;i<n;i++)v.push_back((v[i-2]+v[i-1])%1001);
		std::sort(v.begin(),v.end());
		for(i=r=1;i<n;i++)if(v[i]-v[i-1]>=d)r++;
	}
}