#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int N,K;
	string S;
	cin>>N>>K>>S;
	int M=1,L=0;
	for(int k=K;k>0;k/=2){
		if((k&1)==0){
			puts("Not Found");
			return 0;
		}
		M*=10;
		L++;
	}
	vector<int>s(L);
	for(int i=0;i<M;i++){
		for(int j=i,l=L-1;l>=0;l--)s[l]=j%10+'0',j/=10;
		for(int i=0,j=0;i<N;i++){
			if(S[i]==s[__builtin_ctz(j+1)] && ++j==K){
				puts("Found");
				return 0;
			}
		}
	}
	puts("Not Found");
}