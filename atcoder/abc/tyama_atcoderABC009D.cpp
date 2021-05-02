#include <vector>
#include <cstdio>
using namespace std;
typedef vector<unsigned int>V;
int N;
V z;
V &Me(const V &_x,const V &_y){
	for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		z[i*N+j]=0;
		for(int k=0;k<N;k++)z[i*N+j]=(z[i*N+j]^(_x[i*N+k]&_y[k*N+j]));
	}
	return z;
}
V &Mx(const V &_x){
	for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		z[i*N+j]=0;
		for(int k=0;k<N;k++)z[i*N+j]=(z[i*N+j]^(_x[i*N+k]&_x[k*N+j]));
	}
	return z;
}
main(){
	int M;
	scanf("%d%d",&N,&M);
	V x(N*N),e(N*N),a(N);
	z.resize(N*N);
	for(int i=0;i<N;i++)scanf("%u",&a[i]);
	for(int i=1;i<=N;i++){
		scanf("%u",&x[i-1]);
		if(i<N)x[i*N+i-1]=-1;
		e[(i-1)*N+i-1]=-1;
	}
	if(M<=N){
		printf("%u\n",a[M-1]);
	}else{
		M-=N;
		for(;M;M>>=1){
			if(M&1)e=Me(e,x);
			x=Mx(x);
		}
		unsigned int r=0;
		for(int i=0;i<N;i++)r^=e[i]&a[N-i-1];
		printf("%u\n",r);
	}
}