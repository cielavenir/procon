//usr/bin/env picoc $0 - $@;exit
#include <stdio.h>
int main(){
	int n,y,i,j,k;
	scanf("%d%d",&n,&y);
	for(i=0;i<=n;i++)for(j=0;j<=n-i;j++){
		k=n-i-j;
		if(i*1000+j*5000+k*10000==y){
			printf("%d %d %d\n",k,j,i);
			return 0;
		}
	}
	puts("-1 -1 -1");
	return 0;
}
