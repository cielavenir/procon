#include <iostream>
#include <string>
#include <map>
using namespace std;

long long pow_binary_mod(long long x,long long y,long long m){
	long long z=1;
	for(;y;y>>=1){
		if(y&1)z=z*x%m;
		x=x*x%m;
	}
	return z;
}

int main(){
	int n,m=0;
	string s;
	map<char,int>cnt;
	cin>>n>>s;
	for(int i=0;i<s.size();i++){
		int x=++cnt[s[i]];
		if(m<x)m=x;
	}
	int b=0;
	for(auto &e:cnt){
		if(e.second==m)b++;
	}
	cout<<pow_binary_mod(b,n,1000000007)<<endl;
}