#include <vector>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;

ull pow_binary_mod(ull x,ull y,ull m){
	x%=m;
	ull z = 1;
	for(;y;){
		for(;!(y&1);){
			x = x * x % m;
			y >>= 1;
		}
		y--;
		z = z * x % m;
	}
	return z;
}

int main(){
	ull n,m,k;
	scanf("%llu%llu%llu",&n,&m,&k);
	n%=10;
	if(n==0)puts("0");
	else{
		int mul=pow_binary_mod(n,m,10);
		vector<int>v;
		int z=n,s=0;
		do{
			v.push_back(z);
			s+=z;
			z=z*mul%10;
		}while(z!=n);
		ull d=k/v.size()*s,r=k%v.size();
		for(k=0;k<r;k++)d+=v[k];
		printf("%llu\n",d);
	}
}