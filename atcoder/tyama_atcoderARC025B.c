#include <stdio.h>
int c[101][101];
int main(){
	int h,w,x,i,j,I,J;
	scanf("%d%d",&h,&w);
	for(i=1;i<=h;i++)for(j=1;j<=w;j++){
		scanf("%d",c[i]+j);
		if((i+j)&1)c[i][j]=-c[i][j];
	}
	for(i=1;i<=h;i++)for(j=1;j<=w;j++)c[i][j]+=c[i][j-1];
	for(i=1;i<=h;i++)for(j=1;j<=w;j++)c[i][j]+=c[i-1][j];
	x=0;
	for(i=1;i<=h;i++)for(I=i;I<=h;I++){
		for(j=1;j<=w;j++)for(J=j;J<=w;J++){
			if(
				c[I][J]-c[I][j-1]-c[i-1][J]+c[i-1][j-1]==0 &&
				x<(I-i+1)*(J-j+1)
			)
				x=(I-i+1)*(J-j+1);
		}
	}
	printf("%d\n",x);
	return 0;
}