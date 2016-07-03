#include <stdio.h>
#define MA 16
int M[MA];
long long best[1<<MA];
long long bitDP(int n){
	int N = 1 << n;
	int S,j;
	best[0]=1;
	for(S=0;S<N;S++)for(j=0;j<n;j++){
		int T=S|(1<<j);
		if(S!=T && !(M[j]&T))best[T]+=best[S];
	}
	return best[N-1];
}

int main(){
	int N,m,x,y;
	for(scanf("%d%d",&N,&m);m--;){
		scanf("%d%d",&x,&y);M[x-1]|=1<<(y-1);
	}
	printf("%lld\n",bitDP(N));
	return 0;
}