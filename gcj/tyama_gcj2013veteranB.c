main(t,T,A,a,B,b){
	char s[2];
	for(scanf("%d",&T);t<=T;t++){
		scanf("%s %d'%d\" %d'%d\"",s,&A,&a,&B,&b);
		a=(a+A*12+b+B*12+5*(*s=='B'?1:-1));
		A=a%2,a/=2;
		b=a+4,a=a-4+A;
		printf("Case #%d: %d'%d\" to %d'%d\"\n",t,a/12,a%12,b/12,b%12);
	}
}