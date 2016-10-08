#include <stdio.h>
#include <stdlib.h>
int main(){
	int L,N,R=0;
	scanf("%d%d",&L,&N);
	for(;N--;){
		int a,b;
		scanf("%d%d",&a,&b);
		R+=a*b;
	}
	if(R==0){
		puts("0");
	}else{
		printf("1\n%d %d\n",R>0?-1:1,abs(R));
	}
	return 0;
}