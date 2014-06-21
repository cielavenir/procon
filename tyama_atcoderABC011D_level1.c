#include <stdio.h>
int main(){
	int n,N,R=0,i,j;
	int d,X,Y,x,y;
	scanf("%d%d%d%d",&n,&d,&X,&Y);
	if(X%d||Y%d){puts("0");return 0;}
	X/=d,Y/=d;
	if(n>11)return 1;
	N=1<<(n*2);
	for(i=0;i<N;i++){
		for(x=y=j=0;j<n;j++){
			if(((i>>(j*2))&3)==0)x++;
			if(((i>>(j*2))&3)==1)x--;
			if(((i>>(j*2))&3)==2)y++;
			if(((i>>(j*2))&3)==3)y--;
		}
		if(x==X&&y==Y)R++;
	}
	printf("%.9f\n",R*1.0/N);
	return 0;
}