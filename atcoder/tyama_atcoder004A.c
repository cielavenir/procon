#include <math.h>
N[100][2];
main(n,i,j){
	double d=0,e;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d%d",N[i],N[i]+1);
	for(i=0;i<n-1;i++)for(j=i+1;j<n;j++){
		e=hypot(N[i][0]-N[j][0],N[i][1]-N[j][1]);
		if(e>d)d=e;
	}
	printf("%f\n",d);
	exit(0);
}