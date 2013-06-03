//OSX 10.8.3 amd64 / MacBookAir Mid2012 (Core i7) -> 27sec on clang -O3, 27sec on gcc-mp-4.7 -O3
//Debian Linux wheezy i686 / Athlon II X2 3.08GHz -> 35sec on clang -O3, 48sec on gcc -O3
#include <stdio.h>
#include <math.h>
double x[9999],y[9999],a,b,c,A,B,C,_x,_y,r,X,Y,R=9999999;
int main(){
	int n=0,i,j,k,l;
	for(;~scanf("%lf, %lf,",x+n,y+n);n++);
	for(i=0;i<n;i++,fprintf(stderr,"[*] %d\n",i))for(j=i+1;j<n;j++)for(k=j+1;k<n;k++){ //O(n3)
		a=2*x[j]-2*x[i],b=2*y[j]-2*y[i],c=x[i]*x[i]-x[j]*x[j]+y[i]*y[i]-y[j]*y[j];
		A=2*x[k]-2*x[i],B=2*y[k]-2*y[i],C=x[i]*x[i]-x[k]*x[k]+y[i]*y[i]-y[k]*y[k];
		_x=(b*C-B*c)/(a*B-A*b),_y=(c*A-C*a)/(a*B-A*b);
		r=(x[i]-_x)*(x[i]-_x)+(y[i]-_y)*(y[i]-_y);
		l=0;if(r<R)for(;l<n;l++)if((x[l]-_x)*(x[l]-_x)+(y[l]-_y)*(y[l]-_y)>r+1e-7)break;
		if(l==n)X=_x,Y=_y,R=r,fprintf(stderr,"[+] %f\n",R);
	}
	printf("%f %f %f\n",X,Y,sqrt(R)); //193.238841 198.382466 146.975772
	return 0;
}
// 答: X座標=193.238841 Y座標=198.382466 半径=146.975772