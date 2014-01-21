#define max(a,b)((a)>(b)?(a):(b))
long long BIT[100010], bit_size; // long long は 64bit 整数．
void bit_init(int n){
	memset(BIT,0,n*(sizeof(long long)));
	bit_size = n;
}
long long bit_max(int n){ // [1,n] の最大値
	long long ans = 0;
	while(n > 0){
		ans = max(ans, BIT[n]);
		n &= n-1;
	}
	return ans;
}
void bit_setmax(int n, long long v){ // # [1,n] の最大値を v に更新する
	while (n < bit_size){
		BIT[n] = max(BIT[n], v);
		n += n & (-n);
	}
}
int main(){
	long long N,x,i=0;
	scanf("%lld",&N);
	bit_init(N+1);
	for(; i<N; ++i){
		scanf("%lld",&x);
		long long cost = bit_max(x);
		bit_setmax(x,cost+x);
	}
	printf("%lld\n",(1+N)*N/2 - bit_max(N));
}