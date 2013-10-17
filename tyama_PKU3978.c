#include <stdio.h>
#define size 199999
int numbercount[size];
int table[size];
int main(){
	int i=2,j;
	for(table[0]=table[1]=1;i<size;i++)if(table[i]==0)
		for(j=i*2;j<size;j+=i)table[j]=1;
	for(i=2;i<size;i++)numbercount[i]=numbercount[i-1]+(table[i]^1);
	for(;scanf("%d%d",&i,&j),~i;)printf("%d\n",numbercount[j]-(i?numbercount[i-1]:0));
	return 0;
}