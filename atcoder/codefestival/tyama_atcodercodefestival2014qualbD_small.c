#include <stdio.h>
int H[100000];
int main(){
	int n,i,j,r;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",H+i);
	for(i=0;i<n;i++){
		r=0;
		for(j=i-1;j>=0&&H[j]<=H[i];j--)r++;
		for(j=i+1;j<n&&H[j]<=H[i];j++)r++;
		printf("%d\n",r);
	}
	return 0;
}