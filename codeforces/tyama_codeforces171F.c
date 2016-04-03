#include <stdio.h>
#define M 1000000
int T[M]={1,1};
int rev(int n){
	int r=0;
	for(;n;){
		r=r*10+n%10;
		n/=10;
	}
	return r;
}
int main(){
	int i=1,j,n;
	for(scanf("%d",&n);++i<=M;)if(!T[i])for(j=i+i;j<=M;j+=i)T[j]=1;
	for(i=2;i<=M;i++)if(!T[i]){
		j=rev(i);
		if(j!=i&&!T[j]&&!--n){printf("%d\n",i);return 0;}
	}
}