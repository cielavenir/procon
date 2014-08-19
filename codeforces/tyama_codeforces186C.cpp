#include <iostream>
#include <valarray>
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
	int T;
	long long t,t0;
	//for(scanf("%d",&T);T--;){
		cin>>t;
		V x(n*n);
		V e(n*n);
		z.resize(n*n);

		x[0]=x[3]=3;
		x[1]=x[2]=1;
		e[0]=e[3]=1;
		for(;t;t>>=1){
			if(t&1)e=Me(e,x);
			x=Mx(x);
		}
		cout<<e[0]<<endl;
	//}
}