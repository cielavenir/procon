#include <set>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;

int main(){
	set<pii>se;
	int N;
	for(scanf("%d",&N);N--;){
		int x,y;
		scanf("%d%d",&x,&y);
		pii A={x-20,0},B={x+20,1<<30};
		auto a=se.lower_bound(A),b=se.upper_bound(B);
		for(;a!=b;++a){
			if((a->first-x)*(a->first-x) + (a->second-y)*(a->second-y) < 400)break;
		}
		if(a==b)se.insert({x,y});
	}
	printf("%d\n",se.size());
}