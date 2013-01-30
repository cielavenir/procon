#include <valarray>
#include <cstdio>
using namespace std;
typedef valarray<int>V;
int n,m;
V M(const V &x,const V &y){
	V z(n*n);
	int i=0,j;
	for(;i<n;i++)for(j=0;j<n;j++)z[i*n+j]=(x[slice(i*n,n,1)]*y[slice(j,n,n)]).sum()%m;
	return z;
}
V E(const V &x,const int n){
	if(n==1)return x;
	if(n&1)return M(E(x,n-1),x);
	V y=E(x,n>>1);
	return M(y,y);
}
V s,x;
void O(const V &r){
	int i=0;
    for(;i<n-1;i++)printf("%d ",(r[slice(i*n,n,1)]*s).sum()%m);
    printf("%d\n",(r[slice(i*n,n,1)]*s).sum()%m);
}
main(){
	int i,a,b,c,t;
	for(;scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&t),n;){
		s.resize(n);
		for(i=0;i<n;i++)scanf("%d",&s[i]);
		x.resize(0);
		x.resize(n*n);
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
			O(E(x,t));
		}else{
			for(i=0;i<n;i++)x[i*n+i]=1;
			O(x);
		}
	}
}