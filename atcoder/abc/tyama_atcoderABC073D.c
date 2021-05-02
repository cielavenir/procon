#include <stdio.h>

#define MA 20
int M[MA][MA];
int best[1<<MA][MA];
int shortestHamiltonPath(int s,int n) {
	int N = 1 << n;
	int S,i,j;
	for(S=0;S<N;S++)for(i=0;i<n;i++)best[S][i]=1<<29;
	best[1<<s][s]=0;
	for(S=0;S<N;S++)for(j=0;j<n;j++)if(!(S&(1<<j)))for(i=0;i<n;i++){
		if(best[S|(1<<j)][j] > best[S][i]+M[i][j]){
			best[S|(1<<j)][j] = best[S][i]+M[i][j];
		}
	}
	for(j=1<<29,i=0;i<n;i++)if(j>best[N-1][i])j=best[N-1][i];
	return j;
}

int m[200][200],r[8];
int main(){
	int N,_M,R,a,b,c;
	scanf("%d%d%d",&N,&_M,&R);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)m[i][j]=(1<<29)*(i!=j);
	for(int i=0;i<R;i++)scanf("%d",r+i),r[i]--;
	for(int i=0;i<_M;i++){
		scanf("%d%d%d",&a,&b,&c);
		m[a-1][b-1]=m[b-1][a-1]=c;
	}
	for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		if(m[i][j]>m[i][k]+m[k][j])m[i][j]=m[i][k]+m[k][j];
	}
	for(int i=0;i<R;i++)for(int j=0;j<R;j++)M[i][j]=m[r[i]][r[j]];
	N=1<<29;
	for(int i=0;i<R;i++)if(N>(a=shortestHamiltonPath(i,R)))N=a;
	printf("%d\n",N);
}
