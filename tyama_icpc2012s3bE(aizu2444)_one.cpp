#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

const long long B=1000000000000000003LL;
const long long P=1000000000000000031LL;

long long pow_binary_mod(long long x,long long y,long long mod){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=(__int128_t)z*x%mod;
		x=(__int128_t)x*x%mod;
	}
	return z;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T;
	string s;
	cin>>T>>T>>s;
	long long Brev=pow_binary_mod(B,P-2,P);
	set<long long> se;

	int l=0,r=0;
	long long c=s[0];
	for(;T--;){
		string q;
		cin>>q;
		if(q=="L--"){
			l--;
			c=(s[l]*(__int128_t)pow_binary_mod(B,r-l,P)+c)%P;
		}else if(q=="L++"){
			c=((c-s[l]*(__int128_t)pow_binary_mod(B,r-l,P))%P+P)%P;
			l++;
		}else if(q=="R--"){
			c=((c-s[r])%P+P)%P*(__int128_t)Brev%P;
			r--;
		}else if(q=="R++"){
			r++;
			c=(c*(__int128_t)B+s[r])%P;
		}
		se.insert(c);
	}
	printf("%d\n",se.size());
}
