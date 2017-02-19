#include <stdio.h>

#define MA 20
int M[MA][MA];
int best[1<<MA][MA];
int shortestHamiltonPath(int s,int n) {
	int N = 1 << n;
	int S,i,j;
	for(S=0;S<N;S++)for(i=0;i<n;i++)best[S][i]=0;
	best[1<<s][s]=1;
	for(S=0;S<N;S++)for(j=0;j<n;j++)if(!(S&(1<<j)))for(i=0;i<n;i++){
			if(M[i][j])best[S|(1<<j)][j] += best[S][i];
	}
	for(i=j=0;i<n;i++)j+=best[N-1][i];
	return j;
}

int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		M[a-1][b-1]=M[b-1][a-1]=1;
	}
	printf("%d\n",shortestHamiltonPath(0,n));
}
