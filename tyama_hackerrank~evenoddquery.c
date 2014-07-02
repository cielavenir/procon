#include <stdio.h>
int a[100000];
int main(){
	int N,Q,x,y;
	scanf("%d",&N);
	for(x=0;x<N;x++)scanf("%d",a+x);
	for(scanf("%d",&Q);Q--;){
		scanf("%d%d",&x,&y);
		puts(
			a[x-1]%2 ? "Odd" :
			x==y ? "Even" :
			a[x] ? "Even" : "Odd"
		);
	}
	return 0;
}