long long a[99999],m;
main(n,k,i,j){for(;scanf("%d%d",&n,&k),n>=0;){
	for(i=0;i<n;i++)scanf("%lld",a+i);
	//for(i=0;i<n;i++)for(j=n-1;i+k<j;j--)if(a[i]>a[j]){puts("No");goto next;}
	for(m=i=0;i<n;i++)if(m=i<=k||m>a[i-k-1]?m:a[i-k-1],a[i]<m){puts("No");goto next;}
	puts("Yes");
	next:;
}exit(0);}