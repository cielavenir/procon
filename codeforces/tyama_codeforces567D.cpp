#include <set>
#include <cstdio>
using namespace std;
int ship_num(int A,int s){
	return (s+1)/(A+1);
}
int main(){
	int N,K,A,M,x;
	scanf("%d%d%d%d",&N,&K,&A,&M);
	set<int>blocks={0,N+1};
	int ships=ship_num(A,N);
	for(int i=1;i<=M;i++){
		scanf("%d",&x);
		auto it=blocks.lower_bound(x);
		if(*it==x)continue;
		int r=*it,l=*--it;
		ships=ships-ship_num(A,r-l-1)+ship_num(A,x-l-1)+ship_num(A,r-x-1);
		if(ships<K){
			printf("%d\n",i);
			return 0;
		}
		blocks.insert(x);
	}
	puts("-1");
}