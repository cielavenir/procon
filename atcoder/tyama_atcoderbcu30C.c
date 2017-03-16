#include <stdio.h>
int v[300][300];
int main(){
	int n,m,x,y,r=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		v[x-1][y-1]=1;
	}
	long long r=0;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		long long r0=0;
		for(int k=0;k<n;k++)r0+=v[i][k]*v[k][j];
		r+=r0*r0;
	}
	printf("%lld\n",r);
}
