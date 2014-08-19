#include <queue>
#include <cstdio>
using namespace std;
int m[1000001];
typedef pair<int,int>pii;
main(){
	int n,q,a,v;
	pii P;
	priority_queue<pii>Q;
	for(scanf("%d%d",&n,&q);q--;){
		scanf("%d%d",&a,&v);
		m[a]+=v;
		Q.push(make_pair(m[a],-a));
		for(;P=Q.top(),m[-P.second]!=P.first;Q.pop());
		printf("%d %d\n",-P.second,P.first);
	}
}