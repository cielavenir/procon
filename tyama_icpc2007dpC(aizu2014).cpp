#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define I(n,m) if(find(v.begin(),v.end(),make_pair(n,m))==v.end())ret|=D(n,m,v);
typedef vector<pair<int,int> >V;
char m[99][99];

int D(int i,int j,V&v){
	if(m[i][j]=='B')return 1;
	if(m[i][j]=='W')return 2;
	if(m[i][j]=='X')return 0;
	int ret=0;
	v.push_back(make_pair(i,j));
	I(i-1,j)I(i+1,j)I(i,j-1)I(i,j+1)
	return ret;
}

main(){
	int w,h,i,j,r,s;
	for(;scanf("%d%d",&w,&h),w;printf("%d %d\n",r,s)){
		for(memset(m,'X',sizeof(m)),r=s=0,i=1;i<=h;i++)scanf("%s",m[i]+1),m[i][w+1]='X';
		for(i=1;i<=h;i++)for(j=1;j<=w;j++)if(m[i][j]=='.'){
			V v;for(int x=D(i,j,v),k=0;k<v.size();k++)
				m[v[k].first][v[k].second]=x;
		}
		for(i=1;i<=h;i++)for(j=1;j<=w;j++)
			if(m[i][j]==1)r++;
			else if(m[i][j]==2)s++;
	}
}