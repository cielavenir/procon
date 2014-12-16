#include <stdio.h>
#include <math.h>
int main(){
	const long double pi=acosl(-1);
	int T;
	for(scanf("%d",&T);T--;){
		long double X=0,Y=0,x,y;
		int i=0;
		for(;i<6;i++){
			scanf("%Lf%Lf",&x,&y);
			if(x>=0&&y>=0&&x>X)X=x,Y=y;
		}
		long double z=X/sqrtl(X*X+Y*Y);
		if(z>1)z=1;
		long double ret=180*acosl(z)/pi;
		if(ret>55)ret-=60;
		printf("%.9Lf\n",ret);
	}
}