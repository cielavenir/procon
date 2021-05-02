#include <stdio.h>
int main(){
	int N,T,n,a=0,r=0;
	scanf("%d%d",&N,&T);
	for(;N--;){
		scanf("%d",&n);
		if(n<a)r+=n-a;
		r+=T;
		a=n+T;
	}
	printf("%d\n",r);
	return 0;
}