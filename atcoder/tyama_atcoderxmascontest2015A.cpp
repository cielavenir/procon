#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<long long>V;
int mod;
int n=2;
V z;
V &Me(const V &_x,const V &_y){
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(_x[slice(i*n,n,1)]*_y[slice(j,n,n)]).sum()%mod;
	return z;
}
V &Mx(const V &_x){
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(_x[slice(i*n,n,1)]*_x[slice(j,n,n)]).sum()%mod;
	return z;
}
int main(){
	long long S=0,X;
	int N,t,a,b;
	scanf("%d%lld%d%d%d%d",&N,&X,&t,&a,&b,&mod);
	V x(n*n);
	V e(n*n);
	z.resize(n*n);

	x[0]=a;
	x[1]=x[3]=1;
	e[0]=e[3]=1;
	for(;t;t>>=1){
		if(t&1)e=Me(e,x);
		x=Mx(x);
	}
	for(a=0;a<N;a++){
		S+=X;
		X=(e[0]*X+e[1]*b)%mod;
	}
	printf("%lld\n",S);
}