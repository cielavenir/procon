#include <stdio.h>
#include <string.h>
#define M(a,b)((a)>(b)?(a):(b))
typedef struct{int x,y;}pii;
int i,j,n,k,a,b,d[1001][1001];
pii w(){
	scanf("%d%d",&n,&k);
	memset(d,11,sizeof(d));
	for(i=0;i<n;i++)d[i][i]=0;
	for(;k;k--)scanf("%d%d",&a,&b),d[a][b]=1,d[b][a]=1;
	for(k=0;k<n;k++)for(i=0;i<n;i++)for(j=0;j<n;j++)if(d[i][j]>(a=d[i][k]+d[k][j]))d[i][j]=a;
	int mi=1<<30,ma=0,m;
	for(i=0;i<n;i++){
		m=0;
		for(j=0;j<n;j++)if(m<d[i][j])m=d[i][j];
		if(mi>m)mi=m;
		if(ma<m)ma=m;
	}
	pii p={mi,ma};return p;
}
int main(){
	pii p=w(),q=w();
	i=!printf("%d %d\n",M(p.x+q.x+1,M(p.y,q.y)),p.y+q.y+1);
}
