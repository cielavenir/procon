#include <stdio.h>
#define M 50
int X[M];long long Z[M+1][M*M+1];
int main(){
	int N,A,S=0,i,j,k;
	long long R=0;
	scanf("%d%d",&N,&A);
	for(i=0;i<N;i++)scanf("%d",X+i);
	Z[0][0]=1;
	for(i=0;i<N;i++){
		S+=X[i];
		for(k=i;k>=0;k--)for(j=S;j>=X[i];j--)Z[k+1][j]+=Z[k][j-X[i]];
	}
	for(i=1;i<=N;i++)R+=Z[i][i*A];
	printf("%lld\n",R);
}