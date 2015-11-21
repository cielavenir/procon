#include <stdio.h>
#define M 3000
#define MOD 1000000009
long long pow_binary_mod(long long x,long long y,long long mod){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=z*x%mod;
		x=x*x%mod;
	}
	return z;
}
int Z[6]={1,5,10,50,100,500};
int A[M+1],REV[13];
int main(){
	for(int i=-6;i<=6;i++)REV[6+i]=pow_binary_mod((i+MOD)%MOD,MOD-2,MOD);
	REV[6]=A[0]=1;
	for(int z=0;z<6;z++)for(int i=0;i<=M-Z[z];i++)A[i+Z[z]]+=A[i];
	int T;
	for(scanf("%d",&T);T--;){
		long long m,x,r,s=0,total=1;
		scanf("%lld",&m);
		if(m<=3000)s=A[m];
		else{
			x=m/500,r=m%500;
			for(int l=0;l<6;++l)total=( (x-l+MOD)%MOD*total%MOD*REV[l+1] )%MOD; 
			for(int k=0;k<6;k++){
				long long p=A[k*500+r];
				//for(int l=0;l<6;l++)if(l!=k)p=(x-l+MOD)%MOD*p%MOD*pow_binary_mod(k-l+MOD,MOD-2,MOD)%MOD;
				p=p*total%MOD*pow_binary_mod((x-k+MOD)%MOD,MOD-2,MOD)%MOD;
				s=(s+p)%MOD;
				total=total*REV[k+6+1]%MOD*pow_binary_mod(REV[k+1],MOD-2,MOD)%MOD;
			}
		}
		printf("%lld\n",s);
	}
}