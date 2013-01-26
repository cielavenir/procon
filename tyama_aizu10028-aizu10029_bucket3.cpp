#include <queue>
#include <cstdio>
int main(){
	int n,f;
	std::priority_queue<int,std::vector<int>,std::greater<int> >m;
	for(scanf("%d",&n);n;n--)scanf("%d",&f),m.push(f);f=0;
	for(;!m.empty();m.pop())printf(f?" %d":"%d",m.top()),f=1;
	puts("");
}