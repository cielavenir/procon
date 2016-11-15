#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<__int128_t>V;
int n,m=1000000007;
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
	long long R=0,r;
	int y,i=0,j;
	scanf("%d%lld",&n,&r);
	V x(n*n);
	V e(n*n);
	z.resize(n*n);
	for(;i<n;i++){
		scanf("%d",&y);
		e[i*n+i]=1;
		for(j=0;j<=i;j++)x[i*n+j]=y;
	}
	for(;r;r>>=1){
		if(r&1)e=Me(e,x);
		x=Mx(x);
	}
	for(i=0;i<n;i++)R+=m+e[i*n]-e[i*n+i];
	printf("%lld\n",(R%m+m)%m);
}
