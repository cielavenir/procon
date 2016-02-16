//icpc2012rC
#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<long long>V;
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
	for(;~scanf("%d",&r);){
		int f=1-r%2;
		V x(n*n);
		V e(n*n);
		z.resize(n*n);

		x[0]=1,x[1]=3,x[2]=1,x[3]=1;
		e[0]=1,e[3]=1; //unit

		for(;r;r>>=1){
			if(r&1)e=Me(e,x);
			x=Mx(x);
		}
		printf("%d\n",(int)(2*e[0]-f)%1000);
	}
}