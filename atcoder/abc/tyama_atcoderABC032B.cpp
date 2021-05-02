#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

const int B=999999937;
const int P=1000000007;

void gen_hash(const string &s,vector<long long> &hash){
	long long c=0;
	for(int i=0;i<s.size();i++){
		c=(c*B+s[i])%P;
		hash[i]=c;
	}
}
long long pow_binary_mod(long long x,long long y,long long mod){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=z*x%mod;
		x=x*x%mod;
	}
	return z;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	set<long long>se;
	string s;
	int lq;
	cin>>s>>lq;
	int ls=s.size();
	vector<long long> v(ls);
	gen_hash(s,v);
	long long Brev=pow_binary_mod(B,lq,P);
	int i=lq-1;
	for(;i<ls;i++)se.insert(((v[i]-(i>=lq?v[i-lq]:0)*Brev)%P+P)%P);
	printf("%d\n",se.size());
}