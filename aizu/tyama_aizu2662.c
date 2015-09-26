#include <stdio.h>
#include <math.h>
int main(){
	int N,A=-1,F,T=-1,X,Y;
	int D[2]={-1,-1},S[2];
	for(scanf("%d",&N);N--;){
		int f,a,t,x,y;
		scanf("%d%d%d%d%d",&f,&a,&t,&x,&y);
		if(t==T&&A!=a){
			int z=(X-x)*(X-x)+(Y-y)*(Y-y);
			if(D[t]<z)D[t]=z,S[t]=f-F;
			if(D[t]==z&&S[t]>f-F)S[t]=f-F;
		}
		F=f,A=a,T=t,X=x,Y=y;
	}
	for(N=0;N<2;N++){
		if(D[N]==-1)puts("-1 -1");
		else printf("%f %f\n",sqrt(D[N]),S[N]/60.0);
	}
	return 0;
}