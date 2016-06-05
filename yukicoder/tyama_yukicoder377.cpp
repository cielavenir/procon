#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <cstdio>
using namespace std;
const int M=1000000007;
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long pow(long long x,long long y,long long m){
	long long z=1;
	for(;y;y/=2){
		if(y&1)z=z*x%m;
		x=x*x%m;
	}
	return z;
}
vector<pair<long long,int>> prime_division(long long n){
	unordered_map<long long,int>se;
	FILE *p=popen((string("factor ")+to_string(n)).c_str(),"r");
	long long x;
	fscanf(p,"%lld:",&x);
	for(;~fscanf(p,"%lld",&x);)se[x]++;
	pclose(p);
	vector<pair<long long,int>>v;
	v.insert(v.end(),se.begin(),se.end());
	return v;
}
void divisor_totient(const vector<pair<long long,int>> &a,int d,long long n,long long t,const function<void(long long&,long long&)>&blk){
	if(d==a.size()){
		blk(n,t);
	}else{
		for(int i=0;i<=a[d].second;i++){
			divisor_totient(
				a,d+1,
				n*pow(a[d].first,i,M),
				i==0 ? t : t*(a[d].first-1)*pow(a[d].first,i-1,M),
				blk
			);
		}
	}
}
int main(){
	unordered_map<long long,int>cache;
	long long H,W,K,r=0;
	scanf("%lld%lld%lld",&H,&W,&K);
	auto a=prime_division(H);
	auto b=prime_division(W);
	divisor_totient(a,0,1,1,[&](long long &a,long long &at){
		divisor_totient(b,0,1,1,[&](long long &b,long long &bt){
			long long key=W*H/a/b*gcd(a,b);
			if(cache.find(key)==cache.end())cache.emplace(key,pow(K,key,M));
			r=(r+at*bt%M*cache.at(key))%M;
		});
	});
	printf("%lld\n",r*pow(W*H%M,M-2,M)%M);
}