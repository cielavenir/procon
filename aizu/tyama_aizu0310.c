#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int N,r=0;
	scanf("%d",&N);
	vector<vector<int> >v(N+1);
	v[0].resize(N);
	for(int i=1;i<=N;i++){
		v[i].resize(N+1);
		for(int j=1;j<=N;j++)scanf("%d",&v[i][j]);
	}
	for(int i=0;i<N;i++)for(int j=0;j<=N;j++)v[i+1][j]+=v[i][j];
	for(int i=0;i<=N;i++)for(int j=0;j<N;j++)v[i][j+1]+=v[i][j];
	for(int i0=0;i0<N;i0++)for(int i1=i0+1;i1<=N;i1++){
#if 1
		int r0=v[i0][0]-v[i1][0]-v[i0][1]+v[i1][1],r1=r0;
		int s=0;
		if(N>1)s=v[i0][1]-v[i1][1]-v[i0][2]+v[i1][2];
		r1=max(r1,r0+s);
		for(int k=2;k<N;k++){
			r0+=v[i0][k-1]-v[i0+1][k-1]-v[i0][k]+v[i0+1][k];
			if(i1-i0>1)r0+=v[i1-1][k-1]-v[i1][k-1]-v[i1-1][k]+v[i1][k];
			r0=max(r0,v[i0][k-1]-v[i1][k-1]-v[i0][k]+v[i1][k]);
			s=v[i0][k]-v[i1][k]-v[i0][k+1]+v[i1][k+1];
			r1=max(r1,r0+s);
		}
		r=max(r,r1);
#else
		for(int j0=0;j0<N;j0++)for(int j1=j0+1;j1<=N;j1++){
			int n=v[i0][j0]-v[i1][j0]-v[i0][j1]+v[i1][j1];
			int m=0;
			if(i1-i0>2&&j1-j0>2)m=v[i0+1][j0+1]-v[i1-1][j0+1]-v[i0+1][j1-1]+v[i1-1][j1-1];
			r=max(r,n-m);
		}
#endif
	}
	printf("%d\n",r);
}