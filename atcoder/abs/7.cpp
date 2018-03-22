#include <set>
#include <stdio.h>
int main(){
	int n,i,x;//,r=1;
	std::set<int>se; //int arr[999];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		se.insert(x);
    } 
	printf("%d\n",se.size());
/*
	for(i=0;i<n;i++)scanf("%d",&arr[i]);
	qsort(arr,n,4,compare);
	int t=arr[0];
	for(i=1;i<n;i++){
		if(t!=arr[i]){
			t=arr[i];
			r++;
		}
	}
	printf("%d\n",r);
*/
	return 0;
}
