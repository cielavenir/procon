#include <stdio.h>
#include <math.h>
int main(){
	int T;
	long long a,b,c;
	for(scanf("%d",&T);T--;){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(!a){
			if(!b)puts(c?"0":"3");
			else printf("1 %.12f\n",-c*1.0/b);
		}else{
			if(a<0)a=-a,b=-b,c=-c;
			long double d=(long double)b*b-(long double)4*a*c;
			if(/*d==0*/fabsl(d)<1e-9)printf("1 %.12f\n",-b/2.0/a);
			else if(d<0)puts("0");
			else printf("2 %.12Lf %.12Lf\n",(-b-sqrtl(d))/2/a,(-b+sqrtl(d))/2/a);
		}
	}
	return 0;
}