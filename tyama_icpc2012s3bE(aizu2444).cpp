#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

const vector<long long> B={1000000000000000003LL,1000000000000000009LL};
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
	vector<long long> Brev(2);
	for(int i=0;i<2;i++){
		Brev[i]=pow_binary_mod(B[i],P-2,P);
	}
	set<vector<long long> > se;

	int l=0,r=0;
	vector<long long> c={s[0],s[0]};
	for(;T--;){
		string q;
		cin>>q;
		if(q=="L--"){
			l--;
			for(int i=0;i<2;i++)c[i]=(s[l]*(__int128_t)pow_binary_mod(B[i],r-l,P)+c[i])%P;
		}else if(q=="L++"){
			for(int i=0;i<2;i++)c[i]=((c[i]-s[l]*(__int128_t)pow_binary_mod(B[i],r-l,P))%P+P)%P;
			l++;
		}else if(q=="R--"){
			for(int i=0;i<2;i++)c[i]=((c[i]-s[r])%P+P)%P*(__int128_t)Brev[i]%P;
			r--;
		}else if(q=="R++"){
			r++;
			for(int i=0;i<2;i++)c[i]=(c[i]*(__int128_t)B[i]+s[r])%P;
		}
		se.insert(c);
	}
	printf("%d\n",se.size());
}