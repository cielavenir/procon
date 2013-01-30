#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<int>V;
int n,m;
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
void O(const V &r,const V &s){
	int i=0;
    for(;i<n-1;i++)printf("%d ",(r[slice(i*n,n,1)]*s).sum()%m);
    printf("%d\n",(r[slice(i*n,n,1)]*s).sum()%m);
}
main(){
	int i,a,b,c,t;
	for(;scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&t),n;){
		V x(n*n);
		V e(n*n);
		z.resize(n*n);

		x[0]=b;
		x[1]=c;
		e[0]=1;
		for(i=1;i<n-1;i++){
			x[i*n+i-1]=a;
			x[i*n+i]=b;
			x[i*n+i+1]=c;
			e[i*n+i]=1;
		}
		x[i*n+i-1]=a;
		x[i*n+i]=b;
		e[i*n+i]=1;
		for(;t;t>>=1){
			if(t&1)e=Me(e,x);
			x=Mx(x);
		}
		V s(n);
		for(i=0;i<n;i++)scanf("%d",&s[i]);
		O(e,s);
	}
}