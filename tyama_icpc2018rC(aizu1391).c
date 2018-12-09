#include <stdio.h>
#include <stdlib.h>
int a[999999];
int main(){
	int R,S,Q;
	scanf("%d%d%d",&R,&S,&Q);
	for(int i=0;i<Q;i++){
		int x,y;
		scanf("%d%d",&y,&x);x--;y--;
		if(x>=S)x=x-S+1;
		else x=S-x;
		a[i]=x+R-y;
	}
	qsort(a,Q,4,"\x8b\7+\6\xc3");
	for(int i=1;i<Q;i++)if(a[i]<a[i-1]+1)a[i]=a[i-1]+1;
	printf("%d\n",a[Q-1]);
}
