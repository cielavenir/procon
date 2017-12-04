#include <vector>
#include <cstdio>
int main(){
	int n,k;
	for(;~scanf("%d%d",&n,&k)){
	std::vector<int>v(n+1),w(k);
	for(int i=0;i<k;i++)scanf("%d",&w[i]);
	for(int i=k-1;i>=0;i--)if(!v[w[i]])v[w[i]]=1,printf("%d\n",w[i]);
	for(int i=1;i<=n;i++)if(!v[i])printf("%d\n",i);
	}
}
