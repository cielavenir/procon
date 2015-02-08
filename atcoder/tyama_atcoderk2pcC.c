#include <stdio.h>
int a[50000];
int main(){
	int i,j,A=0,B=0;
	for(i=0;i<50000;i++)a[i]=i*(i+1)/2+1;
	int v[2];
	scanf("%d%d",v,v+1);
	for(j=0;j<2;j++){
		for(i=0;i<50000;i++){
			if(a[i]>v[j]){
				int x=a[i]-v[j];
				A+=x,B+=i+1-x;
				break;
			}
		}
	}
	int x=A+B-2;
	printf("%d\n",a[x]+B-1);
	return 0;
}