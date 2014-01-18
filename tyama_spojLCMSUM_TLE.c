long long gcd(long x,long y){return y?gcd(y,x%y):x;}
main(){
	int t;
	long long x,y,r;
	for(scanf("%d",&t);t--;printf("%lld\n",r)){
		scanf("%lld",&y);
		for(r=0,x=1;x<=y;x++)r+=x/gcd(x,y)*y;
	}
}
/*
main(){
	int t;
	long long x,y,r;
	for(y=0;++y<=1000000;printf("{%lld},",r)){
		for(r=0,x=1;x<=y;x++)r+=x/gcd(x,y)*y;
	}
}*/