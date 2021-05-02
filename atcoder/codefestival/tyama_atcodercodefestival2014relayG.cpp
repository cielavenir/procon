#include <vector>
#include <cstdio>
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	std::vector<int>v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	std::vector<int>bag(20000);
	bag[0]=1;
	for(int i=0;i<n;i++)for(int j=20000-1;j>=v[i];j--){
		bag[j]|=bag[j-v[i]];
	}
	for(int j=m;j<20000;j++)if(bag[j]){
		printf("%d\n",j);
		return 0;
	}
	puts("-1");
}