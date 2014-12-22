#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<long long>V;
int n=2;
V z;
V &Me(const V &_x,const V &_y){
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(_x[slice(i*n,n,1)]*_y[slice(j,n,n)]).sum();
	return z;
}
V &Mx(const V &_x){
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(_x[slice(i*n,n,1)]*_x[slice(j,n,n)]).sum();
	return z;
}
void O(const V &r,const V &s){
	int i=0;
    for(;i<n-1;i++)printf("%d ",(r[slice(i*n,n,1)]*s).sum());
    printf("%d\n",(r[slice(i*n,n,1)]*s).sum());
}
main(){
	int T;
	long long t,t0;
	for(scanf("%d",&T);T--;){
		scanf("%lld",&t),t0=t;
		V x(n*n);
		V e(n*n);
		z.resize(n*n);

		x[0]=x[1]=x[2]=1;
		e[0]=e[3]=1;
		for(;t;t>>=1){
			if(t&1)e=Me(e,x);
			x=Mx(x);
		}
		printf("%lld\n",e[1]);
	}
}