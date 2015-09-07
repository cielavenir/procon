#define M 2000002
#define MOD 1000000007
long long inv[M],fact[M],factr[M];
int main(){
	int i,N;
	for(i=0;i<M;i++)inv[i]=fact[i]=factr[i]=1;
	for(i=2;i<M;i++){
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
		fact[i]=i*fact[i-1]%MOD;
		factr[i]=inv[i]*factr[i-1]%MOD;
	}
	scanf("%d",&N);N++;
	int r=(2*fact[2*N-1])%MOD;
	r=(r*factr[N])%MOD;
	r=(r*factr[N-1])%MOD;
	printf("%d\n",r-1);
}