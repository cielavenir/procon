#include <stdio.h>
int main(){
	int s,g,r=0;
	scanf("%d%d",&s,&g);
	for(;s<g;r++){
		if(g%2)g++;
		else g/=2;
	}
	printf("%d\n",r+s-g);
	return 0;
}