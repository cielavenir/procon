#include <stdio.h>
#define M 50
int X[M];long long Z[M+1][M*M+1];
int main(){
	int N,A,S=0;
	long long R=0;
	scanf("%d%d",&N,&A);
	for(int i=0;i<N;i++)scanf("%d",X+i);
	Z[0][0]=1;
	for(int i=0;i<N;i++){
		S+=X[i];
		for(int k=i;k>=0;k--)for(int j=S;j>=X[i];j--)Z[k+1][j]+=Z[k][j-X[i]];
	}
	for(int i=1;i<=N;i++)R+=Z[i][i*A];
	printf("%lld\n",R);
}
//this code shows C11 is available on (recent) AtCoder.