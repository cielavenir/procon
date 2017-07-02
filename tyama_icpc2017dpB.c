#include <stdio.h>

int main(){
	int T,D,L;
	for(;~scanf("%d%d%d",&T,&D,&L)&&T&&D&&L;){
		int r=0;
		for(int i=0,x,y=0;i<T;i++){
			if(--y>=0)r++;
			scanf("%d",&x);
			if(x>=L)y=D;
		}
		printf("%d\n",r);
	}
}
