#include <set>
#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
int M[11][11]={
	{1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1},
};
int D[][2]={{-1,0},{0,-1},{1,0},{0,1}};
int d[][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
void dfs(int x,int y,int dx,int dy,set<pii> &s){
	if(M[y][x])return;
	s.insert(make_pair(x,y));
	dfs(x+dx,y+dy,dx,dy,s);
}
int main(){
	int i,j,di,dj,r=0;
	for(i=0;i<81;i++)for(j=0;j<81;j++)if(i!=j){
		set<pii> s;
		M[i/9+1][i%9+1]=M[j/9+1][j%9+1]=1;
		for(di=0;di<4;di++)dfs(i%9+1+D[di][0],i/9+1+D[di][1],D[di][0],D[di][1],s);
		for(dj=0;dj<4;dj++)dfs(j%9+1+d[dj][0],j/9+1+d[dj][1],d[dj][0],d[dj][1],s);
		M[i/9+1][i%9+1]=M[j/9+1][j%9+1]=0;
		r+=s.size();
	}
	printf("%d\n",r); //149424
}