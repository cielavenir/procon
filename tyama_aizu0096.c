A[2001],B[4001];main(a,b){
	for(a=0;a<1001;a++)for(b=0;b<1001;b++)A[a+b]++;
	for(a=0;a<2001;a++)for(b=0;b<2001;b++)B[a+b]+=A[a]*A[b];
	for(;~scanf("%d",&a);)printf("%d\n",B[a]);
exit(0);}