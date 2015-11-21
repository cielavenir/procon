#include <stdio.h>

#define MOD 1000000007
long long pow_binary_mod(long long x,long long y,long long mod){
	long long z=1;
	for(;y;y>>=1){
		if((y&1)!=0)z=z*x%mod;
		x=x*x%mod;
	}
	return z;
}

long long V[100001],REV[200002];
int main(){
	int D;
	scanf("%d",&D);D+=1;
	for(int i=-D;i<=D;i++)REV[D+i]=pow_binary_mod((i+MOD)%MOD,MOD-2,MOD);
	REV[D]=1;
	for(int i=0;i<=D;++i)scanf("%lld",V+i);
	//if(V[D]<D)return 1;
	long long s=0,total=1;
	for(int l=0;l<D;++l)total=( (V[D]-l+MOD)%MOD*total%MOD*REV[l+1] )%MOD;
	for(int k=0;k<D;++k){
		long long p=V[k];
		//obvious
		//for(int l=0;l<D;++l)if(l!=k)p=( (V[D]-l+MOD)%MOD*p%MOD*REV[k-l+D] )%MOD;

		//remove if
		//for(int l=0;l<D;++l)p=( (V[D]-l+MOD)%MOD*p%MOD*REV[k+l+1] )%MOD; //k+1 to k+D
		//p=p*pow_binary_mod((V[D]-k+MOD)%MOD,MOD-2,MOD)%MOD;

		p=p*total%MOD*pow_binary_mod((V[D]-k+MOD)%MOD,MOD-2,MOD)%MOD;
		s=(s+p)%MOD;
		total=total*REV[k+D+1]%MOD*pow_binary_mod(REV[k+1],MOD-2,MOD)%MOD;
	}
	printf("%lld\n",s);
	return 0;
}