//icpc2012rC
#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<int>V;
int n=2,m=1000;
V z;
V &Me(const V &_x,const V &_y){
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(_x[slice(i*n,n,1)]*_y[slice(j,n,n)]).sum()%m;
	return z;
}
V &Mx(const V &_x){
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(_x[slice(i*n,n,1)]*_x[slice(j,n,n)]).sum()%m;
	return z;
}
main(){
	int t=1,T,r;
	for(scanf("%d",&T);t<=T;t++){
		scanf("%d",&r);
		V x(n*n);
		V e(n*n);
		z.resize(n*n);

		x[0]=3,x[1]=5,x[2]=1,x[3]=3; //seminar resume
		e[0]=1,e[3]=1; //unit

		for(;r;r>>=1){
			if(r&1)e=Me(e,x);
			x=Mx(x);
		}
		//printf("Case #%d: %03d\n",t,(int)(e[0]+e[2]*2.23606797749979)%1000);
		printf("Case #%d: %03d\n",t,(2*e[0]-1)%1000);
	}
}