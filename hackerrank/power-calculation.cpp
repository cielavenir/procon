#include <vector>
#include <cstdio>
typedef unsigned long long ull;
ull pow_binary_mod(ull x,ull y,ull m){
	ull z=1;
	for(;y;y>>=1){
		if(y&1)z=z*x%m;
		x=x*x%m;
	}
	return z;
}

int main(){
	int T;
	for(scanf("%d",&T);T--;){
		ull K,N,s=1;
		scanf("%llu%llu",&K,&N);
		std::vector<ull>v(100);
		v[0]=0;v[1]=1;
		for(int i=2;i<100;i++){
			v[i]=pow_binary_mod(i,N,100);
			s+=v[i];
		}
		s%=100;
		s*=K/100;
		s%=100;
		for(int i=1;i<=K%100;i++)s+=v[i];
		printf("%02llu\n",s%100);
	}
}