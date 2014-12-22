#include <stdio.h>
#include <math.h>
double x[9999],y[9999],px,py,r,cx,cy,R,move=1;
int main(){
	int n=0,i,k,t;
	for(;~scanf("%lf, %lf,",x+n,y+n);n++);
	for(px=*x,py=*y;move>1e-16;move/=2)for(t=0;t<100;t++){
		for(R=i=0;i<n;i++)if((r=(x[i]-px)*(x[i]-px)+(y[i]-py)*(y[i]-py))>R)R=r,cx=px,cy=py,k=i;
		px+=(x[k]-px)*move;
		py+=(y[k]-py)*move;
	}
	printf("%.15f\n%.15f\n%.15f\n",cx,cy,sqrt(R)); //193.238841 198.382466 146.975772
	return 0;
}