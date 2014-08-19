#include <stdio.h>
#include <limits.h>
int max(int x,int y){
	int N=sizeof(x)*CHAR_BIT;
	return y ^ ( (x ^ y) & ( (y - x) >> (N - 1) ) );
}
int min(int x,int y){
	int N=sizeof(x)*CHAR_BIT;
	return y ^ ( (x ^ y) & ( (x - y) >> (N - 1) ) );
}
int main(){
	int x,y;
	for(;scanf("%d%d",&x,&y),x|y;)printf("%d %d\n",min(x,y),max(x,y));
	return 0;
}