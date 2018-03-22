//usr/bin/env picoc $0 - $@;exit
#include <stdio.h>
int main(){
	int n,a,b,r=0,i,j;
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;i++){
		int s=0;
		j=i;
		for(;j;j/=10)s+=j%10;
		if(a<=s&&s<=b)r+=i;
	}
	printf("%d\n",r);
	return 0;
}
