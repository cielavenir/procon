#include <stdio.h>
int main(){
	int N,i=0,s=0,e;
	scanf("%d",&N);
	for(;i<N;i++){
		scanf("%d",&e);
		s=(s+e-1)%2;
		printf("%d\n",2-s);
	}
}