#include <stdio.h>
#ifdef __cplusplus
	#include <algorithm>
	#define min std::min
#else
	//C99
	int min32(const int x,const int y){return y ^ ( (x ^ y) & ( (x - y) >> 31 ) );}
	#define min min32
#endif

int N,dist[1000][1000];
void output(){
	long long s=0;
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)s+=dist[i][j];
	printf("%lld\n",s);
}
int main(){
	int M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dist[i][j]=(1<<29)*(i!=j);
	for(int m=0;m<M;m++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		dist[a-1][b-1]=dist[b-1][a-1]=c;
	}
	for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	}
	//output();
	scanf("%d",&M);
	for(int m=0;m<M;m++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<N;i++)for(int j=0;j<N;j++){
			dist[i][j]=min(dist[i][j],c+min(dist[i][a-1]+dist[b-1][j],dist[i][b-1]+dist[a-1][j]));
		}
		output();
	}
}