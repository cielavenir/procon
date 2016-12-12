#include <stdio.h>
int T[]={0,1867,1911,1925,1988};
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==0){
		if(b>1988)printf("H%d\n",b-1988);
		else if(b>1925)printf("S%d\n",b-1925);
		else if(b>1911)printf("T%d\n",b-1911);
		else printf("M%d\n",b-1867);
	}else{
		printf("%d\n",T[a]+b);
	}
}
