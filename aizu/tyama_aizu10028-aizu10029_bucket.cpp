#include <map>
#include <cstdio>
int main(){
	int n,f;
	std::map<int,int>m;
	for(scanf("%d",&n);n;n--)scanf("%d",&f),m[f]++;f=0;
	for(auto i=m.begin();i!=m.end();i++)for(;(*i).second;(*i).second--)printf(f?" %d":"%d",(*i).first),f=1;
	puts("");
}