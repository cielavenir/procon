#include <bitset>
#include <cstdio>
using namespace std;
const int M=2000000;
int main(){
	bitset<M>A,B;
	int N,S,T,U,V,Q;
	scanf("%d%d%d%d%d%d",&N,&S,&T,&U,&V,&Q);
	for(int i=0;i<N;i++)A[i]=S&1,S=((long long)S*T+U)%V;
	for(;Q--;){
		scanf("%d%d%d%d",&S,&T,&U,&V);S--,U--;
		//B.reset();for(int i=S;i<T;i++)B[i-S]=A[i];
		B=A<<M-T;
		B>>=S+M-T;
		A^=B<<U;
	}
	for(int i=0;i<N;i++)putchar(A[i]%2?'O':'E');
	putchar('\n');
}