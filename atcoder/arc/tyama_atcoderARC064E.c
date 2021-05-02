#include <stdio.h>
#include <math.h>

double X[1010],Y[1010],R[1010],D[1010][1010],d;
main(){
	int i=1,j,k,N;
	scanf("%lf%lf%lf%lf%d",X,Y,X+1,Y+1,&N);N+=2;
	for(;++i<N;)scanf("%lf%lf%lf",X+i,Y+i,R+i);
	for(i=0;i<N;i++)for(j=i;j<N;j++)D[i][j]=D[j][i]=(d=hypot(X[i]-X[j],Y[i]-Y[j])-R[i]-R[j])>0?d:0;
	for(k=0;k<N;k++)for(i=0;i<N;i++)for(j=0;j<N;j++)if(D[i][j]>(d=D[i][k]+D[k][j]))D[i][j]=d;
	printf("%.9f\n",D[0][1]);
}
