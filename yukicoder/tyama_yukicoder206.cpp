#include <bitset>
#include <cstdio>
int main(){
	std::bitset<1<<17>a,b;
	int L,M,Q;
	scanf("%d%d%d",&L,&M,&Q);
	for(;L--;)scanf("%d",&Q),a.set(Q);
	for(;M--;)scanf("%d",&Q),b.set(Q);
	for(scanf("%d",&Q);Q--;b<<=1)printf("%d\n",(a&b).count());
}