#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
using namespace std;

//ALDS1 14D cannot be solved.
//BWT=O(S+TQlogS) Hash=O(TS)

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

	string s;
	cin>>s;
	int ls=s.size();
	vector<long long> v(ls),hsh(10001);
	gen_hash(s,v);

	//int T;
	//for(cin>>T;T--;){
		string q;
		cin>>q;
		int lq=q.size();
		gen_hash(q,hsh);
		long long hash=hsh[lq-1];
		long long Brev=pow_binary_mod(B,lq,P);
		vector<int> r;
		int i=lq-1;
		for(;i<ls;i++){
			if(v[i]==((i>=lq?v[i-lq]:0)*Brev+hash)%P){
				r.push_back(i-lq+1);
				//break;
			}
		}
		if(!r.empty()){
			for(int i=0;i<r.size();i++)printf("%d\n",r[i]);
			//puts("1");
		}else{
			//puts("0");
		}
	//}
}
