#include <stdio.h>
int main(){
	int m,a,b,x,y,r;
	for(;scanf("%d%d%d%d",&m,&a,&b,&x)>3;){
		for(int g=0,i=1;i<m;i++){
			scanf("%d",&y);
			if(a<=i&&i<=b && x-y>=g)g=x-y,r=i;
			x=y;
		}
		printf("%d\n",r);
	}
	return 0;
}