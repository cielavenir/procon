#define M 2000000
#define MOD 1000000007
long long inv[M],fact[M],factr[M];
int main(){
	int i,T,N,K;
	char C;
	for(i=0;i<M;i++)inv[i]=fact[i]=factr[i]=1;
	for(i=2;i<M;i++){
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		fact[i]=i*fact[i-1]%MOD;
		factr[i]=inv[i]*factr[i-1]%MOD;
	}
	for(scanf("%d",&T);T--;){
		scanf("\n%c(%d,%d)",&C,&N,&K);
		if(C=='P')printf("%lld\n",N<K?0:fact[N]*factr[N-K]%MOD);
		else{
			if(C=='H')N=N+K-1;
			printf("%lld\n",N==-1&&K==0?1:N<K?0:(__int128_t)fact[N]*factr[K]*factr[N-K]%MOD);
		}
	}
}