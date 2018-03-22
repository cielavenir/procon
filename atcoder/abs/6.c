#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int main(){
	int n,i,r=0,t=1;
	int arr[999];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&arr[i]);
	qsort(arr,n,4,compare);
	for(i=0;i<n;i++){
		r+=t*arr[i];
		t=-t;
	}
	printf("%d\n",r);
	return 0;
}
