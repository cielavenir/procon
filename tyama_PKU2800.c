main(){
	long long a=0,i=1,j,r,s,n,k;
	scanf("%lld%lld",&n,&k);
	for(;i<=n;){
		j = k / i;
		r = k % i;
		if(!j){
			a += r * (n - i + 1);
			i = n + 1;
		}else{
			s= r / j;
			if(s + 1 > n - i + 1)s = n - i;
			a += (r + r - s * j) * (s + 1) / 2;
			i += s + 1;
		}
	}
	printf("%lld\n",a);
}