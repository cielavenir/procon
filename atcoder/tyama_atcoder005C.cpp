#include <cstdio>
#include <cstring>
#include <queue>
#define N 2
using namespace std;
typedef pair<pair<int,int>,int>coor;
char m[500][501],*p;int M[500][500][N+1];
main(){
	int h,w,i,j,sx,sy,gx,gy;
	for(scanf("%d%d",&h,&w);i<h;i++){
		scanf("%s",m[i]);
		p=strchr(m[i],'s');
		if(p)sy=i,sx=p-m[i],*p='.';
		p=strchr(m[i],'g');
		if(p)gy=i,gx=p-m[i],*p='.';
	}
	queue<coor>q;
	q.push(make_pair(make_pair(sx,sy),0));
	M[sy][sx][0]=1;
	for(;!q.empty();){
		coor c=q.front();q.pop();
		//printf("%d %d %d\n",c.first.first,c.first.second,c.second);
		if(c.first.second==gy&&c.first.first==gx){puts("YES");return 0;}
		if(0<c.first.first){
			if(m[c.first.second][c.first.first-1]=='#'){
				if(c.second<N&&!M[c.first.second][c.first.first-1][c.second+1]){
					for(i=c.second+1;i<=N;i++)M[c.first.second][c.first.first-1][i]=1;
					q.push(make_pair(make_pair(c.first.first-1,c.first.second),c.second+1));
				}
			}else{
				if(!M[c.first.second][c.first.first-1][c.second]){
					for(i=c.second;i<=N;i++)M[c.first.second][c.first.first-1][i]=1;
					q.push(make_pair(make_pair(c.first.first-1,c.first.second),c.second));
				}
			}
		}
		if(c.first.first<w-1){
			if(m[c.first.second][c.first.first+1]=='#'){
				if(c.second<N&&!M[c.first.second][c.first.first+1][c.second+1]){
					for(i=c.second+1;i<=N;i++)M[c.first.second][c.first.first+1][i]=1;
					q.push(make_pair(make_pair(c.first.first+1,c.first.second),c.second+1));
				}
			}else{
				if(!M[c.first.second][c.first.first+1][c.second]){
					for(i=c.second;i<=N;i++)M[c.first.second][c.first.first+1][i]=1;
					q.push(make_pair(make_pair(c.first.first+1,c.first.second),c.second));
				}
			}
		}
		if(0<c.first.second){
			if(m[c.first.second-1][c.first.first]=='#'){
				if(c.second<N&&!M[c.first.second-1][c.first.first][c.second+1]){
					for(i=c.second+1;i<=N;i++)M[c.first.second-1][c.first.first][i]=1;
					q.push(make_pair(make_pair(c.first.first,c.first.second-1),c.second+1));
				}
			}else{
				if(!M[c.first.second-1][c.first.first][c.second]){
					for(i=c.second;i<=N;i++)M[c.first.second-1][c.first.first][i]=1;
					q.push(make_pair(make_pair(c.first.first,c.first.second-1),c.second));
				}
			}
		}
		if(c.first.second<h-1){
			if(m[c.first.second+1][c.first.first]=='#'){
				if(c.second<N&&!M[c.first.second+1][c.first.first][c.second+1]){
					for(i=c.second+1;i<=N;i++)M[c.first.second+1][c.first.first][i]=1;
					q.push(make_pair(make_pair(c.first.first,c.first.second+1),c.second+1));
				}
			}else{
				if(!M[c.first.second+1][c.first.first][c.second]){
					for(i=c.second;i<=N;i++)M[c.first.second+1][c.first.first][i]=1;
					q.push(make_pair(make_pair(c.first.first,c.first.second+1),c.second));
				}
			}
		}
	}
	puts("NO");
}