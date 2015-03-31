#include <unordered_set>
#include <cstdio>

int main(){
	long long A,B,X;
	scanf("%lld%lld%lld",&A,&B,&X);
	if(A==X){
		puts("0");
		return 0;
	}
	long long a=A,i=0;
	std::unordered_set<long long> se;
	do{
		se.insert(a);
		a=a/2 ^ a%2*B;
		i++;
	}while(a!=X&&se.find(a)==se.end());
	if(a==X)printf("%lld\n",i);
	else puts("-1");
}