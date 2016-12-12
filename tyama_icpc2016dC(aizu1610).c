#include <stdio.h>
#define M 8000000
int T[M];
int main(){
	int m,n,i,j;
	for(;scanf("%d%d",&m,&n),m;){
		for(i=m;i<M;i++)T[i]=0;
		for(i=m;i<M;i++)if(T[i]==0){
			if(n--==0){printf("%d\n",i);break;}
			for(j=i;j<M;j+=i)T[j]=1;
		}
	}
	return 0;
}