#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int D[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
char a[82][82],p[82][82];
int main(){
	int w,h,n,x,y,i,j,k,ret=0,r;
	scanf("%d%d%d",&w,&h,&n);
	if(n>9)return 1;
	for(i=1;i<=h;i++)for(j=1;j<=w;j++)a[i][j]=1;

	vector<pair<int,int> >v;
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());

	do{
		memcpy(p,a,sizeof(a));
		for(r=i=0;i<n;i++)
			for(j=0;j<4;j++)
				for(k=1;p[v[i].second+D[j][1]*k][v[i].first+D[j][0]*k];k++)
					p[v[i].second+D[j][1]*k][v[i].first+D[j][0]*k]=0,r++;
		if(ret<r)ret=r;
	}while(next_permutation(v.begin(),v.end()));
	printf("%d\n",ret+n);
}