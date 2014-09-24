#include <stdio.h>
#include <string.h>
int vec[100001];
int main(){
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)vec[i]=i+1;
	for(i=0;n>1;){
		if(i+=(k-1)%n,i>=n)i-=n;
		printf("%d ",vec[i]);
		for(j=i;j<n;j++)vec[j]=vec[j+1];
		n--;
	}
	printf("%d\n",vec[0]);
}