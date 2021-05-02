#include <stdio.h>
#include <stdbool.h>
int A[5][5],N,K;
bool dfs(int d,int x){
	if(d&&!x)return false;
	if(d==N)return true;
	int i;
	for(i=0;i<K;i++)if(!dfs(d+1,x^A[d][i]))return false;
	return true;
}
int main(){
	int i,j;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++)for(j=0;j<K;j++)scanf("%d",A[i]+j);
	puts(dfs(0,0)?"Nothing":"Found");
	return 0;
}