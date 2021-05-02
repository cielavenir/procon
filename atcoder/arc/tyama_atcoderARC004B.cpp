#include <cstdio>
#include <algorithm>
int N[100];
main(){
	int n,i,m;
	scanf("%d",&n);
	for(m=i=0;i<n;i++)scanf("%d",N+i),m+=N[i];
	if(n==1)i=N[0];
	if(n==2)i=abs(N[0]-N[1]);
	if(n>2){
		std::sort(N,N+n);
		i=2*N[n-1]-m;
		if(i<0)i=0;
	}
	printf("%d\n%d\n",m,i);
}