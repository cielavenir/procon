#include <queue>
#include <cstdio>
typedef struct{
	int x;
	int y;
}dir;
const dir D[]={
	{0,-1},{0,1},{-1,0},{1,0}
};

int main(){
	int W,H,N;
	scanf("%d%d%d",&W,&H,&N);
	std::vector<std::vector<int>>M(H*2+1);
	for(auto&e:M)e.resize(W*2+1);
	for(int n,x,y;N--;){
		scanf("%d%d",&n,&x);
		for(int i=0;i<n;i++,x=y){
			scanf("%d",&y);
			int cx=x%W*2,cy=x/W*2,k=y-x>0?y-x:x-y;
			if(k<W){
				if(y-x>0)M[cy][cx+1]++,M[cy][cx+k*2+1]--;
				else M[cy][cx-k*2+1]++,M[cy][cx+1]--;
			}else{
				if(k/=W,y-x>0)M[cy+1][cx]++,M[cy+k*2+1][cx]--;
				else M[cy-k*2+1][cx]++,M[cy+1][cx]--;
			}
		}
	}
	for(int i=1;i<W;i++)for(int j=0;j<H;j++)M[j*2][i*2+1]+=M[j*2][i*2-1];
	for(int i=0;i<W;i++)for(int j=1;j<H;j++)M[j*2+1][i*2]+=M[j*2-1][i*2];
	M[0][0]=1;
	std::queue<dir>q;
	for(q.push({0,0});!q.empty();){
		dir cur=q.front();q.pop();
		if(W*2+H*2-4-cur.x-cur.y==0)return!printf("%d\n",M[cur.y][cur.x]-1);
		for(auto&d:D){
			if(0<=cur.x+d.x&&cur.x+d.x<W*2-1 && 0<=cur.y+d.y&&cur.y+d.y<H*2-1 && M[cur.y+d.y][cur.x+d.x]){
				dir nxt={cur.x+d.x*2,cur.y+d.y*2};
				if(!M[nxt.y][nxt.x])q.push(nxt),M[nxt.y][nxt.x]=M[cur.y][cur.x]+1;
			}
		}
	}
	puts("Odekakedekinai..");
}