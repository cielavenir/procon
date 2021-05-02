#include <stdio.h>
int main(){
	int a,i,j;
	scanf("%d",&a);
	a=45*45-a;
	for(i=1;i<=9;i++)for(j=1;j<=9;j++)if(i*j==a){
		printf("%d x %d\n",i,j);
	}
	return 0;
}