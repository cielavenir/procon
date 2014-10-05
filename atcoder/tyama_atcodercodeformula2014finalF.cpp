#include <stdio.h>
#define N 100

//1250x1250には収まるらしい。
void dfs(int n,int x,int y,int my){
	if(n){
		if(x+n*2>1250){
			dfs(n,0,my+n,my+n*2);
		}else{
			dfs(n-1,x+n*2,y,my);
			printf("%d %d\n",x+n,y);
		}
	}
}

int main(){
	dfs(N,0,N,N*2);
}