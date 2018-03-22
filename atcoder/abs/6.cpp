#include <vector>
#include <algorithm> //sort,reverse
#include <stdio.h>
int main(){
	int n,i,r=0,t=1;
	scanf("%d",&n);
	std::vector<int>arr(n); //int arr[999];
	for(i=0;i<n;i++)scanf("%d",&arr[i]);
	std::sort(arr.begin(),arr.end()); //qsort(arr,n,4,compare);
	std::reverse(arr.begin(),arr.end());
	for(i=0;i<n;i++){
		r+=t*arr[i];
		t=-t;
	}
	printf("%d\n",r);
	return 0;
}
