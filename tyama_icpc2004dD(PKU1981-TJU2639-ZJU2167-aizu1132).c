#include <math.h>
#include <stdio.h>
#define p2(x) ((x)*(x))
#define mul(rx,ry,x1,y1,x2,y2) ((rx)=(x1)*(x2)-(y1)*(y2),(ry)=(x2)*(y1)+(x1)*(y2))
#define R 1
double X[300],Y[300],hyp,t,pl,dx,dy,x[2],y[2];
int main(){int N,M,m,i,j,k,z;for(;scanf("%d",&N),N;printf("%d\n",M)){
	for(i=0;i<N;i++)scanf("%lf%lf",X+i,Y+i);
	for(M=1,i=0;i<N;i++)for(j=i+1;j<N;j++){
		hyp=hypot(X[j]-X[i],Y[j]-Y[i]);
		if(hyp>2*R)continue;
		//t=( p2(R)-p2(R)+p2(hyp) )/( 2*hyp );
		t=hyp/2;
		pl=sqrt(p2(R)-p2(t));
		dx=(X[j]-X[i])/hyp;
		dy=(Y[j]-Y[i])/hyp;
		mul(x[0],y[0],dx,dy,t,pl);
		mul(x[1],y[1],dx,dy,t,-pl);
		for(z=0;z<2;z++){
			x[z]+=X[i],y[z]+=Y[i];
			for(m=k=0;k<N;k++)if(p2(X[k]-x[z])+p2(Y[k]-y[z])<p2(R)+1e-9)m++;
			if(M<m)M=m;
		}
	}
}return 0;}