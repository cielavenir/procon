#include <stdio.h>
int field[1001][1001];
int damage[1002][1002];
int main(){
	int N,K,i,j,R=0;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++){
		int x,y,h;
		scanf("%d%d%d",&x,&y,&h);
		field[y+500][x+500]=h;
	}
	for(i=0;i<K;i++){
		int x,y,w,h,d;
		scanf("%d%d%d%d%d",&x,&y,&w,&h,&d);
		x+=500,y+=500;
		int xe=x+w+1,ye=y+h+1;
		if(xe>1001)xe=1001;
		if(ye>1001)ye=1001;
		damage[y][x]+=d;
		damage[y][xe]-=d;
		damage[ye][x]-=d;
		damage[ye][xe]+=d;
	}
	for(i=0;i<1001;i++)for(j=1;j<1001;j++)damage[i][j]+=damage[i][j-1];
	for(i=1;i<1001;i++)for(j=0;j<1001;j++)damage[i][j]+=damage[i-1][j];
	for(i=0;i<1001;i++)for(j=0;j<1001;j++)if(field[i][j]>damage[i][j])R+=field[i][j]-damage[i][j];
	printf("%d\n",R);
	return 0;
}