#include <stdio.h>
#include <stdlib.h> //strtol
#include <math.h> //fabs,fmin
double mod(double n,double d){
	return n-(int)(n/d)*d;
}
void cmyk(double c,double m,double y,double k){
	double r[3];
	r[0]=1-fmin(1,c*(1-k)+k);
	r[1]=1-fmin(1,m*(1-k)+k);
	r[2]=1-fmin(1,y*(1-k)+k);
	printf("RGB(%.0f,%.0f,%.0f)\n",r[0]*255,r[1]*255,r[2]*255);
}
void hsl(double h,double s,double l){
	double c=s*(1-fabs(2*l-1));
	h/=60;
	double x=c*(1-fabs(mod(h,2)-1));
	double r[3];
	r[0]=r[1]=r[2]=0;
	int cidx=mod(h+1,6)/2;
	int xidx=(int)mod(h,3)^1;
	r[cidx]+=c;
	r[xidx]+=x;
	double m=l-c/2;
	for(xidx=0;xidx<3;xidx++)r[xidx]+=m;
	printf("RGB(%.0f,%.0f,%.0f)\n",r[0]*255,r[1]*255,r[2]*255);
}
void hsv(double h,double s,double v){
	double c=s*v;
	h/=60;
	double x=c*(1-fabs(mod(h,2)-1));
	double r[3];
	r[0]=r[1]=r[2]=v-c;
	int cidx=mod(h+1,6)/2;
	int xidx=(int)mod(h,3)^1;
	r[cidx]+=c;
	r[xidx]+=x;
	printf("RGB(%.0f,%.0f,%.0f)\n",r[0]*255,r[1]*255,r[2]*255);
}
void hex(const char *s){
	int n=strtol(s+1,NULL,16);
	printf("RGB(%d,%d,%d)\n",(n>>16)&0xff,(n>>8)&0xff,(n>>0)&0xff);
}
int main(){
	double a,b,c,d;
	char s[99];
	for(;~(scanf("%s",s));){
		if(*s=='('){
			sscanf(s,"(%lf,%lf,%lf,%lf)",&a,&b,&c,&d);
			cmyk(a,b,c,d);
		}else if(s[2]=='L'){
			sscanf(s,"HSL(%lf,%lf,%lf)",&a,&b,&c);
			hsl(a,b/100,c/100);
		}else if(s[2]=='V'){
			sscanf(s,"HSV(%lf,%lf,%lf)",&a,&b,&c);
			hsv(a,b/100,c/100);
		}else{
			hex(s);
		}
	}
	return 0;
}