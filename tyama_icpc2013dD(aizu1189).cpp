#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define t_max 10000001
char M[1001][1001];
short S[1001][1001];
int P[1001][1001];
char table[t_max];
pair<short,short>m[t_max];
int m_rev[t_max];
pair<short,int> dfs(int x,int y){
	if(y==1001)return make_pair(0,0);
	if(S[x][y]>=0)return make_pair(S[x][y],P[x][y]);
	int m=0,m_place=0,i=-1;
	for(;i<2;i++){
		if(x+i<0||1000<x+i)continue;
		pair<short,int> p=dfs(x+i,y+1);
		if(m<p.first||(m==p.first&&m_place<p.second))m=p.first,m_place=p.second;
	}
	if(m==0){
		if(M[x][y])return make_pair(S[x][y]=1,P[x][y]=m_rev[x*1001+y]);
		return make_pair(S[x][y]=0,P[x][y]=0);
	}else{
		return make_pair(S[x][y]=m+M[x][y],P[x][y]=m_place);
	}
}
main(){
	int k=1,z,x,y,i,n,s;
	m[k]=make_pair(x=500,y=500),m_rev[x*1001+y]=k,k++;
	for(z=2;z<=1000;z+=2){
		x++,y++;
		for(i=0;i<z;i++)m[k]=make_pair(x,--y),m_rev[x*1001+y]=k,k++;
		for(i=0;i<z;i++)m[k]=make_pair(--x,y),m_rev[x*1001+y]=k,k++;
		for(i=0;i<z;i++)m[k]=make_pair(x,++y),m_rev[x*1001+y]=k,k++;
		for(i=0;i<z;i++)m[k]=make_pair(++x,y),m_rev[x*1001+y]=k,k++;
	}
	table[0]=table[1]=1;
	for(x=2;x<t_max;x++)if(!table[x])for(y=x*2;y<t_max;y+=x)table[y]=1;
	for(;scanf("%d%d",&n,&s),n;){
		memset(M,0,sizeof(M));
		memset(S,0xff,sizeof(S));
		memset(P,0,sizeof(P));
		for(i=1;i<=n;i++)if(!table[i])M[m[i].first][m[i].second]=1;
		pair<short,int> p=dfs(m[s].first,m[s].second);
		printf("%d %d\n",p.first,p.second);
	}
}