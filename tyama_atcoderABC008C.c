#include <stdio.h>
int a[100];
int main(){
	int n,i=0,j,k;
	scanf("%d",&n);
	for(;i<n;i++)scanf("%d",a+i);
	double r=0;
	for(i=0;i<n;i++){
		k=0;
		for(j=0;j<n;j++)if(i!=j&&a[i]%a[j]==0)k++;
		r+=((k/2)+1.0)/(k+1);
	}
	printf("%.9f\n",r);
	return 0;
}