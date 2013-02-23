#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
main(){
	int n,i;
	unsigned int s,x,m;
	for(;scanf("%d",&n),n;){
		for(s=i=0;i<n;i++)scanf("%u",&x),s+=x;
		vector<unsigned int>v;
		for(i=0;i<n-1;i++)scanf("%u",&x),v.push_back(x);
		sort(v.begin(),v.end());
		for(i=n-1,m=s*n;i;m=s*i,i--)if(s+=v[i-1],s*i<m)break;
		printf("%u\n",m);
	}
}