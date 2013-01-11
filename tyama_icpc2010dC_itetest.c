//icpc2010dC test using InformationScience2008[3] ite()
a[181],b1[1000000],b2[1000000];
void ite(n){
	int m,k,l,i;
	b1[0] = b2[0] = 0;
	for(m=1;m<=n;m++){
		i = 0;
		k = l = -1;
		for(i=1;i<181;i++){
			if(m >= a[i] && b1[m-a[i]] >= 0 && (k < 0 || b1[m-a[i]] + 1 < k))
				k = b1[m-a[i]] + 1;
			if((a[i]&1) && m >= a[i] && b2[m-a[i]] >= 0 && (l < 0 || b2[m-a[i]] + 1 < l))
				l = b2[m-a[i]] + 1;
		}
		b1[m] = k;
		b2[m] = l;
	}
}

main(n){
	for(n=1;n<181;n++)a[n]=n*(n+1)*(n+2)/6;
	ite(999999);
	for(;scanf("%d",&n),n;)printf("%d %d\n",b1[n],b2[n]);
	exit(0);
}