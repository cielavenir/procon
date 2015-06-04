#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<long long>V;
int n=2,m=1000000007;
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
int main(){
	int T,a,b,r;
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&a,&b,&r);r--;
		V x(n*n);
		V e(n*n);
		z.resize(n*n);

		x[0]=x[1]=x[2]=1;
		e[0]=1,e[3]=1;

		for(;r;r>>=1){
			if(r&1)e=Me(e,x);
			x=Mx(x);
		}
		printf("%lld\n",(e[0]*b+e[1]*a)%m);
	}
}