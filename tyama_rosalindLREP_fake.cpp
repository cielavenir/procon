#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <cstdio>
#include <cstring>
#include <gmpxx.h>
using namespace std;
//typedef unsigned long long bigint;
typedef mpz_class bigint;
int main(){
	unordered_map<char,int>b={{'A',0},{'T',1},{'G',2},{'C',3}};
	int n,i,j,k;
	string S;
	cin>>S>>n;
	S=S.substr(0,S.size()-1);
for(k=100;;k--){
	map<bigint,int>m;
	bigint hash=0,mask=0;
	for(i=0;i<k;i++){
		hash=hash<<2|b[S[i]];
		mask=mask<<2|3;
	}
	m[hash]++;
	for(;i<S.size();i++){
		hash=(hash<<2|b[S[i]])&mask;
		if(++m[hash]==n){puts(S.substr(i-k+1,k).c_str());return 0;}
	}
}
}