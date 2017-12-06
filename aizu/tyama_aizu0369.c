#include <stdio.h>
#include <math.h>
int main(){
	int N,X,x;
	double r=0,h;
	scanf("%d%d",&N,&X);
	for(int i=0;i<N;i++){
		scanf("%d%lf",&x,&h);
		r=fmax(r,h/x);
	}
	printf("%f\n",r*X);
}
