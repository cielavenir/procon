#include <stdio.h>
int a[100001];
int main(){
	int T,N,i;
	for(scanf("%d",&T);T--;){
		scanf("%d",&N);
		for(i=1;i<=N;i++)scanf("%d",a+i),a[i]+=a[i-1];
		for(i=1;i<=N;i++)if(a[i-1]==a[N]-a[i])break;
		puts(i<=N?"YES":"NO");
	}
}