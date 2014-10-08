#include <stdio.h>
#include <stdlib.h>
int c[10],n;
void dfs(int _n,int m,int v){
	if(_n==0){
		printf("%0*d\n",n,v);
		exit(0);
	}
	int i=0;
	for(;i<10;i++)if(m>=c[i])dfs(_n-1,m-c[i],v*10+i);
}
	
int main(){
	int m,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<10;i++)scanf("%d",c+i);
	dfs(n,m,0);
	puts("NA");
	exit(0);
}