main(){
	long long x,y;
	scanf("%lld%lld",&x,&y);
	for(;y;y/=2)x++;
	printf("%lld\n",x-1);
	return 0;
}