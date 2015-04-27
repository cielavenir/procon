#include <stdio.h>
#include <math.h>
int main(){
	double c,d;
	scanf("%lf",&d);
	int di=d;
	c=sqrt(2)*d;
	if(d<sqrt(di*di+1)&&c<di+1)c=di+1;
	printf("%.9f\n",c);
	return 0;
}