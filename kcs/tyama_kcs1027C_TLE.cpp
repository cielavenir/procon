#include <iostream>
#include <string>
#include <functional>
#include <cstdio>
using namespace std;

string fractal(int depth,int n){
	if(depth==0)return "";
	string s=fractal(depth-1,n/10);
	return s+(char)(n%10+'0')+s;
}
bool seq(int K,function<bool(string)> f){
	int M=1,L=0;
	for(;K>0;K/=2){
		if((K&1)==0)return false;
		M*=10;
		L++;
	}
	for(int i=0;i<M;i++){
		char s[9];
		sprintf(s,"%0*d",L,i);
		if(f(s /*fractal(L,i))*/))return true;
	}
	return false;
}
int main(){
	int N,K;
	string S;
	cin>>N>>K>>S;
	if(!seq(K,[&](string sub){
		for(int i=0,j=0;i<N;i++){
			if(S[i]==sub[__builtin_ctz(j+1)] && ++j==K){
				puts("Found");
				return true;
			}
		}
		return false;
	}))puts("Not Found");
}