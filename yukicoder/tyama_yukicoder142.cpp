#include <vector>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;
int main(){
	int N,S,T,U,V,Q;
	scanf("%d%d%d%d%d%d",&N,&S,&T,&U,&V,&Q);
	vector<ull>A((N+127)/64),B((N+127)/64);
	for(int i=0;i<N;i++){
		A[i/64]|=(ull)S%2<<(i%64);
		S=((ull)S*T+U)%V;
	}
	for(;Q--;){
		scanf("%d%d%d%d",&S,&T,&U,&V);S--,U--;
		int L=(T-S+63)/64;
		for(int i=0;i<L;i++){
			B[i]=A[S/64+i]>>S%64;
			if(S%64)B[i]|=A[S/64+i+1]<<(64-S%64);
		}
		if(V=(T-S)%64)B[L-1]=B[L-1]<<(64-V)>>(64-V);
		for(;L--;){
			A[U/64+i]^=B[i]<<U%64;
			if(U%64)A[U/64+i+1]^=B[i]>>(64-U%64);
		}
	}
	for(;++L<N;)putchar((A[L/64]>>(L%64)&1)?'O':'E');
	putchar('\n');
}