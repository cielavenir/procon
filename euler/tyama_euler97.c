const long long mod=1000000000000LL;
long long f(long long a,long long b,long long c,long long d){
	const long long F1=1000000;
	const long long F2=mod/F1;
	long long r=a,n=b,p=c;
	for(;p;p>>=1){
	    if(p&1)r=(r%F1*n + (r/F1^0)*(n%F2)*F1)%mod;
	    n=(n%F1*n + (n/F1^0)*(n%F2)*F1)%mod;
	}
	return (r+d)%mod;
}
int main(){
	int T;
	long long a,b,c,d,r=0;
	for(scanf("%d",&T);T--;){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		r=(r+f(a,b,c,d))%mod;
	}
	printf("%012lld\n",r);
}