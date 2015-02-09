#include <iostream>
#include <valarray>
#include <gmpxx.h>
using namespace std;
typedef long long val_t;
typedef valarray<val_t>V;
const int MOD=1000000007;

V z(4);
V &Me(const V &_x,const V &_y){
	int i=0,j;
	for(;i<2;i++)for(j=0;j<2;j++)z[i*2+j]=(_x[slice(i*2,2,1)]*_y[slice(j,2,2)]).sum()%MOD;
	return z;
}
V &Mx(const V &_x){
	int i=0,j;
	for(;i<2;i++)for(j=0;j<2;j++)z[i*2+j]=(_x[slice(i*2,2,1)]*_x[slice(j,2,2)]).sum()%MOD;
	return z;
}

val_t pow_binary_mod(val_t x,mpz_class y){
	val_t z=1;
	for(;y!=0;y>>=1){
		if((y&1)!=0)z=z*x%MOD;
		x=x*x%MOD;
	}
	return z;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	val_t r=1;
	for(cin>>T;T--;){
		val_t c;
		mpz_class d;
		cin>>c>>d;
		if(d>MOD-1)d%=MOD-1;
		val_t fib;
		{
			V x(4);x[0]=x[1]=x[2]=1;
			V e(4);e[0]=e[3]=1;
			for(c--;c!=0;c>>=1){
				if((c&1)!=0)e=Me(e,x);
				x=Mx(x);
			}
			fib=e.sum()%MOD;
		}
		r=r*pow_binary_mod(fib,d)%MOD;
	}
	cout<<r<<endl;
}