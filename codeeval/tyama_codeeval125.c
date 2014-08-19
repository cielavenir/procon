main(r){
	unsigned int n;
	for(;~scanf("%u",&n);printf("%d\n",r%3))for(r=0;n;n>>=1)r+=n&1;
}