#include <vector>
#include <cstdio>
int main(){
	int N,r,s,i;
	for(;~scanf("%d",&N)&&N;printf("%d\n",r)){
		std::vector<int>a(N);
		for(s=i=0;i<N;i++)scanf("%d",&a[i]),s+=a[i];
		for(r=i=0;i<N;i++)r+=a[i]*N<=s;
	}
}
