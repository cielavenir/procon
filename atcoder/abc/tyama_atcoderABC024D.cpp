#include <vector>
#include <cstdio>
using namespace std;
typedef long long val_t;
const int M=1000000007;

val_t pow_binary_mod(val_t x,val_t y){
	val_t z=1;
	for(;y!=0;y>>=1){
		if((y&1)!=0)z=z*x%M;
		x=x*x%M;
	}
	return z;
}
val_t inv(val_t x){return pow_binary_mod(x,M-2);}

int main(){
	long long A,B,C;
	scanf("%lld%lld%lld",&A,&B,&C);
	long long ab=A*B%M,bc=B*C%M,ca=C*A%M,z=inv((ab-bc+ca+M)%M);
	long long r=(bc-ca+M)*z%M;
	long long c=(bc-ab+M)*z%M;
	printf("%lld %lld\n",r,c);
}