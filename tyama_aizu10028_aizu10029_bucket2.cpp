#include <set>
#include <cstdio>
int main(){
	int n,f;
	std::multiset<int>m;
	for(scanf("%d",&n);n;n--)scanf("%d",&f),m.insert(f);f=0;
	for(auto i=m.begin();i!=m.end();i++)printf(f?" %d":"%d",(*i)),f=1;
	puts("");
}