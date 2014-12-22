#include <stdio.h>
#include <stdbool.h>
#define N 6
void my_reverse(int *a,int start,int size){
	int end=start+size-1;
	for(;start<end;start++){
		int z=a[start];a[start]=a[end];a[end]=z;
		end--;
	}
}
bool my_next_permutation(int *a,int n,int size){
	if(n<0||size<n)return false;
	int i;
	my_reverse(a,n,size-n);
	for(i=size-2;i>=0;i--)if(a[i]<a[i+1])break;
	if(i<0){
		my_reverse(a,0,size);
		return false;
	}
	int k=i;
	for(i=size-1;i>=k+1;i--)if(a[k]<a[i])break;
	int l=i;
	int z=a[k];a[k]=a[l];a[l]=z;
	my_reverse(a,k+1,size-(k+1));
	return true;
}
int main(){
	int r=0,i;
	int e0[N*2],f0[N*2];
	for(i=0;i<N;i++)e0[i]=f0[i]=0,e0[N+i]=f0[N+i]=1;
	int e[N*2+1];
	int f[N*2+1];
	e[0]=f[0]=0;
	do{
		for(i=0;i<N*2;i++)e[i+1]=e[i]+e0[i];
		do{
			for(i=0;i<N*2;i++){
				f[i+1]=f[i]+f0[i];
				if(e[i]==f[i]&&e[i+1]==f[i+1])break;
			}
			if(i==N*2)r++;
		}while(my_next_permutation(f0,N*2,N*2));
	}while(my_next_permutation(e0,N*2,N*2));
	printf("%d\n",r);
}