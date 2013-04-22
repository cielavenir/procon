#include <stdio.h>
#define M 999
int table[M]={1,1};
int main(){
	int i=2,j,k=0,N=100;
	for(;i<M;i++)if(!table[i]){
		printf("%d\n",i);
		if(++k==N)return 0;
		for(j=i*2;j<M;j+=i)table[j]=1;
	}
	puts("M is too small");
	return 1;
}