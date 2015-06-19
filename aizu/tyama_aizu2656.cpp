#include <stdio.h>
#include <math.h>
double calc(int tA,int vA,int tB,int vB){
	return (double)(tA*vA+tB*vB)/(vA+vB);
}
int main(){
	int T,D,tA,tB,dA,dB,iA,iB;
	scanf("%d%d%d%d%d%d",&T,&D,&tA,&tB,&dA,&dB);
	double r=1<<30;
	for(iA=0;iA*dA<=D;iA++)for(iB=0;iA*dA+iB*dB<=D;iB++){
		double t=fabs(T-calc(tA,iA*dA,tB,iB*dB));
		if(r>t)r=t;
	}
	printf("%f\n",r);
	return 0;
}