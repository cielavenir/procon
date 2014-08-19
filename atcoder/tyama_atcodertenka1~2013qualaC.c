#include <stdio.h>
#define M 100
int m[M+3][M+3];
int x,y;
int grid(int I,int J){
	int i,j,k;
	for(j=0;j<x;j++)for(k=1;k<=m[I][j];k++)if(m[I][j+k]==m[I][j])return 0;
	for(i=0;i<y;i++)for(k=1;k<=m[i][J];k++)if(m[i+k][J]==m[i][J])return 0;
	return 1;
}
int dfs(int n){
	int i,j,k,r=0;
	if(n==x*y)return 1;
	i=n/x,j=n%x;
	for(k=1;k<=3;k++){
		m[i][j]=k;
		if(grid(i,j))r+=dfs(n+1);
	}
	m[i][j]=0;
	return r;
}
int main(){
	scanf("%d%d",&x,&y);
	//if(x>100||y>100)return 1; //RE
	//Oh dear!
	x=20<x?20+x%4:x;
	y=20<y?20+y%4:y;
	printf("%d\n",dfs(0));
	return 0;
}