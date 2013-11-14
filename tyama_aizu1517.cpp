#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
int M[15][15],N[15][15];
int D[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int main(){
	int n,m,x,y,o,r,c,s,a;
	scanf("%d%d",&n,&m);
	for(y=0;y<n;y++)for(x=0;x<n;x++)scanf("%d",M[y]+x);
	for(;m--;){
		scanf("%d%d",&o,&r);r--;
		if(o==0){
			scanf("%d%d%d",&c,&s,&a);c--;
			if(a){
				memcpy(N,M,sizeof(M));
				for(y=0;y<s;y++)for(x=0;x<s;x++){
					if(a==90)N[r+y][c+x]=M[r+s-x-1][c+y];
					else if(a==180)N[r+y][c+x]=M[r+s-y-1][c+s-x-1];
					else if(a==270)N[r+y][c+x]=M[r+x][c+s-y-1];
				}
				memcpy(M,N,sizeof(M));
			}
		}else if(o==1){
			scanf("%d%d",&c,&s);c--;
			for(y=r;y<r+s;y++)for(x=c;x<c+s;x++)M[y][x]^=1;
		}else if(o==2){
			y=M[r][0];for(x=0;x<n-1;x++)M[r][x]=M[r][x+1];
			M[r][n-1]=y;
		}else if(o==3){
			y=M[r][n-1];for(x=n-1;x>0;x--)M[r][x]=M[r][x-1];
			M[r][0]=y;
		}else if(o==4){
			scanf("%d",&c);c--;
			queue<pii>q;
			a=M[r][c],M[r][c]^=1;
			q.push(make_pair(r,c));
			for(;!q.empty();){
				pii p=q.front();q.pop();
				for(s=0;s<4;s++){
					y=p.first+D[s][0],x=p.second+D[s][1];
					if(0<=x&&x<n&&0<=y&&y<n&&M[y][x]==a){
						M[y][x]^=1;
						q.push(make_pair(y,x));
					}
				}
			}
		}
	}
	for(y=0;y<n;y++)for(x=0;x<n;x++)printf(x<n-1?"%d ":"%d\n",M[y][x]);
}