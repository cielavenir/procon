#include <stdio.h>
#include <stdlib.h>
int main(){
	int N,i=0;
	int a[1000];
	scanf("%d",&N);
	for(;i<N;i++)scanf("%d",a+i);
	qsort(a,N,4,"\x8b\7+\6\xc3");
	printf("%f\n",(a[N/2]+a[~-N/2])/2.0);
}
