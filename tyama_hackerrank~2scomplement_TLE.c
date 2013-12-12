int main(){
	int t,a,b;
	for(scanf("%d",&t);t--;){
		long long r=0;
		scanf("%d%d",&a,&b);
		for(;a<=b;a++){
			r+=__builtin_popcount(a);
		}
		printf("%lld\n",r);
	}
}