#pragma GCC optimize("O3")
#pragma GCC target("avx")
#include <stdio.h>
//yukicoder does not support C99
int x[100000];
int main(){
	int n,d,k,r,s;
	scanf("%d%d%d",&n,&d,&k);
	for(int i=0;i<n;i++)scanf("%d",x+i);
	for(int i=0;i<n;i++){
		int e=d+1;
		int f=x[i];
		if(e>n-i)e=n-i;
		for(int j=0;j<e;j++)if(f<x[i+j])f=x[i+j];
		if(r<f-x[i])r=f-x[i],s=i;
	}
	if(r==0)puts("0");
	else{
		int e=d+1;
		if(e>n-s)e=n-s;
		for(int j=0;j<e;j++)if(r==x[s+j]-x[s]){
			printf("%lld\n%d %d\n",(long long)r*k,s,s+j);
			break;
		}
	}
}
