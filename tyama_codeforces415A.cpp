#include <vector>
#include <cstdio>
int main(){
	int n,m,i,j,x;
	scanf("%d%d",&n,&m);
	std::vector<int>v(n);
	for(i=0;++i<=m;){
		scanf("%d",&x);
		for(j=x-1;j<n&&!v[j];j++)v[j]=x;
	}
	for(i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",v[i]);
}