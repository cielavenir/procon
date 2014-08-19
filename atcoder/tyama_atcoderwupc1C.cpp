#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int s[501][501],t[501][501];

main(){
	int x,y,i,j,_x,_y,px,py,qx,qy,rx,ry;
	scanf("%d%d",&y,&x);
		for(getchar(),j=0;j<y;getchar(),j++)
			for(i=0;i<x;i++)
				s[j][i]=getchar();
		for(i=0;i<x;i++)
			for(j=0;j<y;j++){
				if(s[j][i]=='S')px=i,py=j;
				if(s[j][i]=='C')qx=i,qy=j;
				if(s[j][i]=='G')rx=i,ry=j;
				if(s[j][i]!='#')s[j][i]=0;
			}
		memcpy(t,s,sizeof(t));
		queue<int>q;
		q.push((px<<16)|py);s[q.front()&0xffff][q.front()>>16]=1;
		for(;!q.empty();){
			_x=q.front()>>16,_y=q.front()&0xffff;q.pop();
			if(s[_y][_x-1]==0)q.push(((_x-1)<<16)|(_y)),s[_y][_x-1]=s[_y][_x]+1;
			if(s[_y][_x+1]==0)q.push(((_x+1)<<16)|(_y)),s[_y][_x+1]=s[_y][_x]+1;
			if(s[_y-1][_x]==0)q.push(((_x)<<16)|(_y-1)),s[_y-1][_x]=s[_y][_x]+1;
			if(s[_y+1][_x]==0)q.push(((_x)<<16)|(_y+1)),s[_y+1][_x]=s[_y][_x]+1;
			if(s[qy][qx])break;
		}
		if(q.empty())puts("-1"),exit(0);
		while(!q.empty())q.pop();
		q.push((qx<<16)|qy);t[q.front()&0xffff][q.front()>>16]=1;
		for(;!q.empty();){
			_x=q.front()>>16,_y=q.front()&0xffff;q.pop();
			if(t[_y][_x-1]==0)q.push(((_x-1)<<16)|(_y)),t[_y][_x-1]=t[_y][_x]+1;
			if(t[_y][_x+1]==0)q.push(((_x+1)<<16)|(_y)),t[_y][_x+1]=t[_y][_x]+1;
			if(t[_y-1][_x]==0)q.push(((_x)<<16)|(_y-1)),t[_y-1][_x]=t[_y][_x]+1;
			if(t[_y+1][_x]==0)q.push(((_x)<<16)|(_y+1)),t[_y+1][_x]=t[_y][_x]+1;
			if(t[ry][rx])break;
		}
		if(q.empty())puts("-1"),exit(0);
		printf("%d\n",s[qy][qx]-1+t[ry][rx]-1);
	exit(0);
}