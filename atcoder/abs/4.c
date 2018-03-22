//usr/bin/env picoc $0 - $@;exit
#include <stdio.h>
int main(){
	int a,b,c,x,i,j,k,r=0;
	scanf("%d%d%d%d",&a,&b,&c,&x);
	for(i=0;i<=x/500;i++)for(j=0;j<=(x-500*i)/100;j++){
		k=x-500*i-100*j;
		r+=k%50==0&&c>=k/50&&a>=i&&b>=j;
	}
	printf("%d\n",r);
	return 0;
}
