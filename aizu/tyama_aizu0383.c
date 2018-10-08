#include <stdio.h>
#include <math.h>
int main(){
	int a,b,x;
	scanf("%d%d%d",&a,&b,&x);x=(x+499)/500;
	int k[x+1];k[0]=0,k[1]=fmin(a,b);
	for(int i=2;i<=x;i++){
		k[i]=fmin(k[i-2]+a,k[i-1]+b);
	}
	printf("%d\n",k[x]);
}
