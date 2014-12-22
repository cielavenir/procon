#include <stdio.h>
char tatami[99][99];
int corner[99][99],h,w;
int D[2][3]={{0,1,'-'},{1,0,'|'}};
int dfs(int i,int j){
	if(i==h){
		for(i=0;i<h;i++)puts(tatami[i]);
		return 1;
	}
	if(j==w)return dfs(i+1,0);
	if(tatami[i][j])return dfs(i,j+1);
	int k=0,l,r=0;
	for(;k<2;k++)if(i+D[k][0]<h&&j+D[k][1]<w&&!tatami[i+D[k][0]][j+D[k][1]]){
		tatami[i][j]=tatami[i+D[k][0]][j+D[k][1]]=D[k][2];
		for(l=0;l<4;l++)corner[i+l/2*(D[k][0]+1)][j+l/2*(D[k][1]+1)]++;
		for(l=0;l<4;l++)if(corner[i+l/2*(D[k][0]+1)][j+l/2*(D[k][1]+1)]>3)break;
		if(l==4)r+=dfs(i,j+1);
		for(l=0;l<4;l++)corner[i+l/2*(D[k][0]+1)][j+l/2*(D[k][1]+1)]--;
		tatami[i][j]=tatami[i+D[k][0]][j+D[k][1]]=0;
	}
	return r;
}
int main(){for(;~scanf("%d%d",&h,&w);)dfs(0,0);return 0;}
/*
4 7
----|--
|--||||
|--||||
----|--
--|----
||||--|
||||--|
--|----
|--|--|
|||||||
|||||||
|--|--|
5 6
------
|----|
||--||
||--||
|----|
|----|
||--||
||--||
|----|
------
*/