#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int n,i,r=1,t;
	int arr[999];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",arr+i);
	qsort(arr,n,4,compare);
	t=arr[0];
	for(i=1;i<n;i++){
		if(t!=arr[i]){
			t=arr[i];
			r++;
		}
	}
	printf("%d\n",r);
	return 0;
}
