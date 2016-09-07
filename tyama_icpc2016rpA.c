#include <stdio.h>
int a[9999];
int f(int n,int d){return n==0||(d-n%10==1&&f(n/10,n%10));}
int main(){
	int n,r=-1,i=0,j,q;
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	for(i=0;i<n;i++)for(j=i+1;j<n;j++)if(q=a[i]*a[j],r<q&&f(q/10,q%10))r=q;
	printf("%d\n",r);
}