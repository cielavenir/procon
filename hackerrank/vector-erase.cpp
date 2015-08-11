#include <vector>
#include <algorithm>
#include <cstdio>
int main(){
	int N;
	scanf("%d",&N);
	std::vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	v.erase(v.begin()+a-1);
	v.erase(v.begin()+b-1,v.begin()+c-1);
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)printf(i<v.size()-1?"%d ":"%d\n",v[i]);
}