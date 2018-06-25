#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

const long long B=1000000000000000003LL;
const long long P=1000000000000000031LL;

long long mul(long long x,long long y,long long m){
	long long z=0;
	for(;y;y>>=1){
		if(y&1){z+=x;if(z>=m)z-=m;}
		x+=x;if(x>=m)x-=m;
	}
	return z;
}

long long pow_binary_mod(long long x,long long y,long long m){
	long long z=1;
	for(;y;y>>=1){
		if(y&1)z=mul(z,x,m);
		x=mul(x,x,m);
	}
	return z;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	string s;
	cin>>N>>s;
	long long Brev=pow_binary_mod(B,P-2,P);
	vector<long long> o(N+1),p(N+1);p[0]=1;
	for(int i=1;i<=N;i++){
		p[i]=p[i-1];o[i]=o[i-1];
		if(s[i-1]=='>'){
			p[i]=mul(p[i],B,P);
		}else if(s[i-1]=='<'){
			p[i]=mul(p[i],Brev,P);
		}else if(s[i-1]=='+'){
			o[i]=(o[i]+p[i])%P;
		}else if(s[i-1]=='-'){
			o[i]=(o[i]-p[i]+P)%P;
		}
	}
	map<long long,int>m;
	long long r=0;
	for(int i=N;i>=1;i--){
		m[o[i]]++;
		r+=m[(mul(o[N],p[i-1],P)+o[i-1])%P];
	}
	printf("%lld\n",r);
}
