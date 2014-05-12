#include <algorithm>
#include <cstdio>
int a[100],f[100];
int main(){
	int total0=0,total1=0,n,i=0,j;
	scanf("%d",&n);
	if(n>11)return 1;
	for(;i<n;i++)scanf("%d",a+i);
	std::sort(a,a+n);
	do{
		total0++;
		for(i=0;i<n;i++)f[i]=1;
		for(i=0;i<n-1;i++)for(j=i+1;j<n;j++)if(a[j]%a[i]==0)f[j]^=1;
		for(i=0;i<n;i++)total1+=f[i];
	}while(std::next_permutation(a,a+n));
	printf("%.9f\n",total1*1.0/total0);
}