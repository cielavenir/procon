// g++ -O2 tyama_atcoderijpc1C*.cpp
// TLE on Subtask2/6
#include <cstring>
int B[99999],A[99999],W[99999],N;
void init(int n, int a[]){memcpy(B,a,(N=n)*sizeof(int));}
void update(int i, int x){B[i]=x;}

int M(int l,int r){
	if(l+1>=r)return 0;
	if(l+2==r){
		if(A[l]<=A[l+1])return 0;
		//int z=A[l];A[l]=A[l+1];A[l+1]=z;
		A[l]^=A[l+1];A[l+1]^=A[l];A[l]^=A[l+1];
		return 1;
	}
	int m = (l+r)/2,i=l, j=m, k=l;
	int cl=M(l, m),cr=M(m,r),c=0;
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

int train(int p, int q){
	q++;
	memcpy(A,B+p,(q-p)*sizeof(int));
	return M(0,q-p);
}