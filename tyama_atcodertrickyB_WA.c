#include <stdio.h>
#include <math.h>
int main(){
	int T;
	long long a,b,c;
	long double d;
	for(scanf("%d",&T);T--;){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(!a){
			if(!b)puts(c?"0":"3");
			else printf("1 %.12Lf\n",-c*1.0L/b);
		}else{
			if(a<0)a=-a,b=-b,c=-c;
			if(b*b<4*a*c)puts("0");
			else if(b*b==4*a*c)printf("1 %.12Lf\n",-b/2.0L/a);
			else{
				d=1.0L*b*b-4.0L*a*c;
				printf("2 %.12Lf %.12Lf\n",(-b-sqrtl(d))/2/a,(-b+sqrtl(d))/2/a);
			}
		}
	}
	return 0;
}