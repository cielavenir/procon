#include <valarray>
#include <cstdio>
using namespace std;
main(){
	int n,q,i,x;
	scanf("%d%d",&n,&q);
	valarray<int>v(n);
	for(i=0;i<n;i++)scanf("%d",&x),v[i]=x;
	for(i=0;i<q;i++){
		scanf("%d",&x);
		valarray<int>u=v;
		u%=x;
		printf("%d\n",u.max());
	}
}