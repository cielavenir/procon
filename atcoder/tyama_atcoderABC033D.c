#include <stdio.h>
#define S(n)(n)*(n)
int x[2000],y[2000],tbl[2000][2000];
int main(){
	int N,i,j,k,r0=0,r1=0,r2=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d%d",&x[i],&y[i]);
	for(i=0;i<N;i++)for(j=0;j<i;j++)tbl[i][j]=S(x[i]-x[j])+S(y[i]-y[j]);
	for(i=0;i<N;i++)for(j=0;j<i;j++)for(k=0;k<j;k++){
		int a=tbl[i][j],b=tbl[j][k],c=tbl[i][k],m=a;
		if(m<b)m=b;
		if(m<c)m=c;
		m=a+b+c-m-m;
		r0+=m>0;
		r1+=m==0;
		r2+=m<0;
	}
	printf("%d %d %d\n",r0,r1,r2);
	return 0;
}