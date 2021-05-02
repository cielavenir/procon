#include <utility>
#include <cstdio>
int table[]={0,1,2,3,3,4,5,6,7,7};
typedef std::pair<long long,bool>pllb;
pllb calc2(long long n){
	if(!n){
		return std::make_pair(0,false);
	}else{
		pllb p=calc2(n/10);
		return p.second ? std::make_pair(p.first*8+7,true) : std::make_pair(p.first*8+table[n%10],n%10==4||n%10==9);
	}
}
long long calc(long long n){
	return n-calc2(n).first;
}
int main(){
	long long n,m;
	scanf("%llu%llu",&n,&m);
	printf("%llu\n",calc(m)-calc(n-1));
	return 0;
}