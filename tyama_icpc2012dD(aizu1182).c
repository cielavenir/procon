//C99 or C++98
#include <stdio.h>
int A[100][100],B[20][100][100];
int main(){
	const int INF=1<<29;
	int n,m,c,s,g;
	for(;scanf("%d%d%d%d%d",&n,&m,&c,&s,&g),n;){
		//距離行列を初期化
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			A[i][j]=INF;
			for(int k=0;k<c;k++)B[k][i][j]=INF;
		}
		//鉄道会社ごとに駅間の最短距離を求める
		for(int i=0;i<m;i++){
			int x,y,d,c;
			scanf("%d%d%d%d",&x,&y,&d,&c);
			x--,y--,c--;
			if(B[c][x][y]>d)B[c][x][y]=d;
			if(B[c][y][x]>d)B[c][y][x]=d;
		}
		int p[c];
		for(int x=0;x<c;x++){
			scanf("%d",&p[x]);
			for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
				if(B[x][i][j]>B[x][i][k]+B[x][k][j]){
					B[x][i][j]=B[x][i][k]+B[x][k][j];
				}
			}
		}
		//全ての距離を駅間のコストに変換する
		for(int k=0;k<c;k++){
			int x=p[k],q[x],r[x];
			q[0]=0;
			for(int i=1;i<x;i++)scanf("%d",&q[i]);
			for(int i=0;i<x;i++)scanf("%d",&r[i]);
			for(int i=0;i<n;i++)for(int j=0;j<i;j++)if(B[k][i][j]<INF){
				int y=x-1;
				for(;B[k][i][j]<q[y];y--);
				int v=r[y]*(B[k][i][j]-q[y]);
				for(y--;y>=0;y--)v+=r[y]*(q[y+1]-q[y]);
				if(A[i][j]>v)A[i][j]=A[j][i]=v;
			}
		}
		//駅間の最短コストを求める
		for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			if(A[i][j]>A[i][k]+A[k][j]){
				A[i][j]=A[i][k]+A[k][j];
			}
		}
		printf("%d\n",A[s-1][g-1]>=INF ? -1 : A[s-1][g-1]);
	}
	return 0;
}