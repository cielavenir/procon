#include <valarray>
#include <vector>
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
int main(){
	int N,K,C,T;
	scanf("%d%d%d%d",&N,&K,&C,&T);C--;
	vector<int>a(K),b(K),t(K);
	for(int i=0;i<K;i++)scanf("%d%d%d",&a[i],&b[i],&t[i]),a[i]--;
	n=N*5;
	V x(n*n);
	V e(n*n);
	z.resize(n*n);
	for(int i=0;i<n;i++)e[i*n+i]=1;
	for(int i=0;i<K;i++)for(int j=0;j<N;j++){
		int nj=j<a[i]?j+b[i]:j<a[i]+b[i]?j-a[i]:j;
		x[j*5*n+nj*5+t[i]-1]++;
	}
	for(int i=0;i<N;i++)for(int j=1;j<5;j++)x[(i*5+j)*n+i*5+j-1]++;
	for(;T;T>>=1){
		if(T&1)e=Me(e,x);
		x=Mx(x);
	}
	printf("%lld\n",(long long)e[C*5*n]);
}
