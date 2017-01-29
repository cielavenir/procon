#!/usr/bin/env rdmd
import core.stdc.stdio;
import std.math;
int main(){
	int T;
	long a,b,c;
	for(scanf("%d",&T);T--;){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(!a){
			if(!b)puts(c?"0":"3");
			else printf("1 %.12f\n",-c*1.0/b);
		}else{
			if(a<0)a=-a,b=-b,c=-c;
			double d=b*b-4.0*a*c;
			if(/*d==0*/fabs(d)<1e-9)printf("1 %.12f\n",-b/2.0/a);
			else if(d<0)puts("0");
			else{
				// acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
				double x,y;
				if(b>0){
					x = (-b-sqrt(d))/2/a;
					y = c*1.0/a/x;
				}else{
					y = (-b+sqrt(d))/2/a;
					x = c*1.0/a/y;
				}
				printf("2 %.12f %.12f\n",x,y);
			}
		}
	}
	return 0;
}
