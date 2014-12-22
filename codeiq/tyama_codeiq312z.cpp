#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
//2=>6,3=>20,4=>56,...,10=>9728 (10+9<<9)
int main(){
	int N=4;
	int i=1,j,m,M=0,x;
	vector<int>v((1<<N)+1);
	for(;i<1<<N;i++)v[i]=i;
	do{
		for(i=m=0;i<1<<N;i++){
			x=v[i]^v[i+1];
			for(j=0;j<N;j++)m+=(x>>j)&1;
		}
		if(M<m)M=m;
	}while(next_permutation(v.begin()+1,v.begin()+(1<<N)));
	printf("%d\n",M);
}
//CodeIQ 270 別解: N=5に対しこのプログラムが走りきった時が地球滅亡日である :p
//O((1<<N)!)とは誠に恐ろしいオーダーである。