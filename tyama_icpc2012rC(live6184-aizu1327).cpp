#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<int>V;
int n,m;
V M2(const V &x,const V &y){
	V z(n*n);
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(x[slice(i*n,n,1)]*y[slice(j,n,n)]).sum()%m;
	return z;
}
V M1(const V &x){
	V z(n*n);
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(x[slice(i*n,n,1)]*x[slice(j,n,n)]).sum()%m;
	return z;
}
V E(const V &x,const int n){
	if(n==1)return x;
	if(n&1)return M2(E(x,n-1),x);
	return M1(E(x,n>>1));
}
void O(const V &r,const V &s){
	int i=0;
    for(;i<n-1;i++)printf("%d ",(r[slice(i*n,n,1)]*s).sum()%m);
    printf("%d\n",(r[slice(i*n,n,1)]*s).sum()%m);
}
main(){
	int i,a,b,c,t;
	for(;scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&t),n;){
		V s(n);
		for(i=0;i<n;i++)scanf("%d",&s[i]);
		V x(n*n);
		if(t){
			x[0]=b;
			x[1]=c;
			for(i=1;i<n-1;i++){
				x[i*n+i-1]=a;
				x[i*n+i]=b;
				x[i*n+i+1]=c;
			}
			x[i*n+i-1]=a;
			x[i*n+i]=b;
			O(E(x,t),s);
		}else{
			for(i=0;i<n;i++)x[i*n+i]=1;
			O(x,s);
		}
	}
}