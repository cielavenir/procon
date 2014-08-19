N,a[99],b1[1000000];
void ite(n){
	int m,k,l,i;
	b1[0] = 0;
	for(m=1;m<=n;m++){
		i = 0;
		k = l = -1;
		for(i=0;i<N;i++){
			if(m >= a[i] && b1[m-a[i]] >= 0 && (k < 0 || b1[m-a[i]] + 1 < k))
				k = b1[m-a[i]] + 1;
		}
		b1[m] = k;
	}
}

main(m,i){
	scanf("%d%d",&m,&N);
	for(i=0;i<N;i++)scanf("%d",a+i);
	ite(m);
	printf("%d\n",b1[m]);
	exit(0);
}