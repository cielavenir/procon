#!/usr/bin/rdmd
import std.stdio, std.algorithm;
const int N=6;
void my_reverse(T)(T[] a,int start,int size){
	int end=start+size-1;
	for(;start<end;start++){
		T z=a[start];a[start]=a[end];a[end]=z;
		end--;
	}
}
bool my_next_permutation(T)(T[] a,int n){
	int siz=cast(int)a.length;
	if(n<0||siz<n)return false;
	int i;
	my_reverse(a,n,siz-n);
	for(i=cast(int)siz-2;i>=0;i--)if(a[i]<a[i+1])break;
	if(i<0){
		my_reverse(a,0,siz);
		return false;
	}
	int k=i;
	for(i=cast(int)siz-1;i>=k+1;i--)if(a[k]<a[i])break;
	int l=i;
	T z=a[k];a[k]=a[l];a[l]=z;
	my_reverse(a,k+1,siz-(k+1));
	return true;
}
bool my_next_permutation(T)(T[] a){
	return my_next_permutation(a,cast(int)a.length);
}
int main(){
	int r=0,i;
	int[] e0=new int[N*2],f0=new int[N*2];
	for(i=0;i<N;i++)e0[N+i]=f0[N+i]=1;
	do{
		do{
			int flg=0;
			int zero1=0;
			int zero2=N;
			int one1=0;
			int one2=N;
			for(i=0;i<N*2;i++){
				if(e0[i]==0)zero1++;
				if(e0[i]==1)one1++;
				if(f0[N*2-1-i]==0)zero2--;
				if(f0[N*2-1-i]==1)one2--;
				if(zero1==zero2)flg++;
				if(one1==one2)flg++;
			}
			if(flg>=2)r++;
		}while(my_next_permutation(f0));
		//}while(nextPermutation(f0));
	}while(my_next_permutation(e0));
	//}while(nextPermutation(e0));
	writeln(r);
	return 0;
}