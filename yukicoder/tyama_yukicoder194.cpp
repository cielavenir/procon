#include <valarray>
#include <vector>
#include <cstdio>
using namespace std;
typedef valarray<__int128_t>V; //lol
int _N,MOD=1000000007;
V z;
V &M(const V &_x,const V &_y){
	int i=0,j;
	for(;i<_N;i++)for(j=0;j<_N;j++)z[i*_N+j]=(_x[slice(i*_N,_N,1)]*_y[slice(j,_N,_N)]).sum()%MOD;
	return z;
}
int main(){
	int N,i;
	long long K;
	scanf("%d%lld",&N,&K);
	vector<long long>A(N);
	for(i=0;i<N;i++)scanf("%lld",&A[i]);
	long long accum=0,f,s;
	for(i=0;i<N;i++)accum=(accum+A[i])%MOD;
	if(N>50){
		for(s=accum;i<K;i++){
			A.push_back(accum);
			s=(s+accum)%MOD;
			accum=(accum+A[i]-A[i-N]+MOD)%MOD;
		}
		f=A[K-1];
	}else{
		_N=N+1;
		V x(_N*_N);
		V e(_N*_N);
		z.resize(_N*_N);
		for(i=0;i<_N;i++)e[i*_N+i]=x[i]=1;
		for(i=0;i<N;i++)x[_N+i+1]=1;
		for(i=0;i<N-1;i++)x[(i+2)*_N+i+1]=1;
		for(K-=N;K;K>>=1){
			if(K&1)e=M(e,x);
			x=M(x,x);
		}
		f=0,s=accum*x[0];
		for(i=1;i<=N;i++)f=(f+e[_N+i]*A[N-i])%MOD,s=(s+e[i]*A[N-i])%MOD;
	}
	printf("%lld %lld\n",f,s);
}