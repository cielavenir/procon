#include <stdio.h>
#include <stdlib.h>
int A[999999],W[999999];
long long M(int l,int r){
	if(l+1>=r)return 0;
	if(l+2==r){
		if(A[l]<=A[l+1])return 0;
		int z=A[l];A[l]=A[l+1];A[l+1]=z;
		return 1;
	}
	int m = (l+r)/2,i=l, j=m, k=l;
	long long cl=M(l, m),cr=M(m,r),c=0;
	while(i<m&&j<r){
		if(A[i]<=A[j])W[k++]=A[i++];
		else{
			W[k++]=A[j++];
			c+=m-i;
		}
	}
	while(i<m)W[k++]=A[i++];
	while(j<r)W[k++]=A[j++];
	for(i=l;i<r;i++)A[i]=W[i];
	return cl+cr+c;
}
int a[16];
int main(){
	int z=0,parity;
	for(int y=0;y<4;y++)for(int x=0;x<4;x++){
		scanf("%d",a+y*4+x);
		int k=a[y*4+x];
		if(k){
			A[z++]=k;
			k--;
			int tx=k%4,ty=k/4;
			int d=abs(y-ty)+abs(x-tx);
			if(d>1){puts("No");return 0;}
		}else{
			int tx=3,ty=3;
			parity=abs(y-ty);
		}
	}
	puts((M(0,z)+parity)%2?"No":"Yes");
}