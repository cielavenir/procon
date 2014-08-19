#include <vector>
#include <cstdio>
std::vector<std::vector<int>>V={
	{0},
	{1},
	{2,4,8,6},
	{3,9,7,1},
	{4,6},
	{5},
	{6},
	{7,9,3,1},
	{8,4,2,6},
	{9,1},
};

int main(){
	int a,i;
	long long n;
	for(;~scanf("%d%lld",&a,&n);){
		std::vector<long long>ret(10);
		for(i=0;i<V[a].size();i++)ret[V[a][i]]=n/V[a].size();
		for(i=0;i<n%V[a].size();i++)ret[V[a][i]]++;
		for(i=0;i<10;i++)printf(i<9?"%d: %lld, ":"%d: %lld\n",i,ret[i]);
	}
}