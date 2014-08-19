#include <stdio.h>
#include <math.h>
int main(){
	long double d;
	scanf("%Lf",&d);
	d=(-1+sqrtl(1+40400*d))/202;
	printf("%.0Lf\n",ceill(d*d));
}