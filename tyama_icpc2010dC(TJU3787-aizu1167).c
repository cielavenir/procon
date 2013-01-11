a[181],m1[1000000],m2[1000000],T;
int s(p,n,f){
	int *m=p,d=180;
	if(!n)return 0;
	if(m[n]<1000000)return m[n];
	for(;d;d--){
		if(a[d]>n||(f&&!(a[d]&1)))continue;
		T=s(p,n-a[d],f)+1;
		if(m[n]>T)m[n]=T;
	}
	return m[n];
}

main(n){
	for(n=1;n<181;n++)a[n]=n*(n+1)*(n+2)/6;
	memset(m1,99,sizeof(m1));
	memset(m2,99,sizeof(m2));
	for(;scanf("%d",&n),n;)printf("%d %d\n",s(m1,n,0),s(m2,n,1));
	exit(0);
}