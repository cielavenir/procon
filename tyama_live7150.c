#include <stdio.h>
#include <math.h>
int main(){
	int p,a,b,c,d,n,k=0;
	double ret=0,ma=0,q;
	scanf("%d%d%d%d%d%d",&p,&a,&b,&c,&d,&n);
	for(;++k<=n;){
		q=sin(a*k+b)+cos(c*k+d)+2;
		if(ma<q)ma=q;
		if(ret<ma-q)ret=ma-q;
	}
	printf("%f\n",ret*p);
	return 0;
}