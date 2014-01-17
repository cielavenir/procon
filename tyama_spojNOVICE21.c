main(){
	int t;
	long long a,b,n,r;
	for(scanf("%d",&t);t--;printf("%lld\n",r)){
		scanf("%lld%lld%lld",&a,&b,&n);
		r=0;
		if(!a)a=1,r=1;
		r+=b/n-(a-1)/n;
	}
}