long long a[199999],S,s;
main(t,i,j,n,l){for(scanf("%d",&t);~scanf("%d%lld",&n,&S);){ //strip scanf("%d",&t) for live2678
	for(i=0;i<n;i++)scanf("%lld",a+i);
	for(i=j=s=0;s<S&&j<n;j++)s+=a[j];
	if(s<S){puts("0");continue;}
	for(l=j,s-=a[i],i++;i<n;s-=a[i],i++){
		for(;s<S&&j<n;j++)s+=a[j];
		if(s>=S&&l>j-i)l=j-i;
	}
	printf("%d\n",l);
}}