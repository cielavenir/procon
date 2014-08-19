int Z(int *a,int *b){return *b-*a;}
a[999],i;main(n,j){
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	qsort(a,n,4,Z);
	long long r=1;
	for(i=0;i<n&&(j=a[i]-i/4)>0;i++)r+=j;
	i=!printf("%lld\n",r);
}