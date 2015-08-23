#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *B;
long long R,S;
void my_reverse(int *a,int start,int size){
	int end=start+size-1;
	for(;start<end;start++){
		S-=abs(a[start]-B[start]);
		S-=abs(a[end]-B[end]);
		int z=a[start];a[start]=a[end];a[end]=z;
		S+=abs(a[start]-B[start]);
		S+=abs(a[end]-B[end]);
		end--;
	}
}
bool my_next_permutation(int *a,int n,int size){
	if(n<0||size<n)return false;
	int i;
	//my_reverse(a,n,size-n);
	for(i=size-2;i>=0;i--)if(a[i]<a[i+1])break;
	if(i<0){
		my_reverse(a,0,size);
		return false;
	}
	int k=i;
	for(i=size-1;i>=k+1;i--)if(a[k]<a[i])break;
	int l=i;
	S-=abs(a[k]-B[k]);
	S-=abs(a[l]-B[l]);
	int z=a[k];a[k]=a[l];a[l]=z;
	S+=abs(a[k]-B[k]);
	S+=abs(a[l]-B[l]);
	my_reverse(a,k+1,size-(k+1));
	return true;
}
int main(){
	int N,K,i;
	scanf("%d%d",&N,&K);
	int *A=(int*)malloc(4*N);
	B=(int*)malloc(4*N);
	for(i=0;i<N;i++)scanf("%d",A+i);
	for(i=0;i<N;i++)scanf("%d",B+i);
	for(i=0;i<N;i++)S+=abs(A[i]-B[i]);
	for(;K--;)R+=S,my_next_permutation(A,N,N);
	printf("%lld\n",R);
	free(A);
	free(B);
}