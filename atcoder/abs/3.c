//usr/bin/env picoc $0 - $@;exit
#include <stdio.h>
int main(){
	int n,x,r=1<<29;
	for(scanf("%d",&n);n--;){
		int r0=0;
		scanf("%d",&x);
		for(;x%2<1;x/=2)r0++;
		if(r>r0)r=r0;
	}
	printf("%d\n",r);
	return 0;
}
