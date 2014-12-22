#include <algorithm>
#include <cstdio>

int T[]={
0b1111110,
0b0110000,
0b1101101,
0b1111001,
0b0110011,
0b1011011,
0b1011111,
0b1110000,
0b1111111,
0b1111011,
};
int M[10][10];
int main(){
	for(int i=0;i<10;i++)for(int j=0;j<10;j++){
		int s=0,k=0;
		for(;k<7;k++)s+=((T[i]^T[j])>>k)&1;
		M[i][j]=s;
	}
	int a[]={0,1,2,3,4,5,6,7,8,9};
	int R=99;
	do{
		int r=0;
		for(int i=0;i<9;i++)r+=M[a[i]][a[i+1]];
		R=std::min(R,r);
	}while(std::next_permutation(a,a+10));
	printf("%d\n",R); //13
}