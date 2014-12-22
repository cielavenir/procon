a[100000];
main(){
	int n,i,j;
	long long s,m=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",a+i);
	for(i=0;i<n;i++){
		for(s=j=0;j<n;j++)s+=(long long)(j+1)*a[(i+j)%n];
		if(m<s)m=s;
	}
	printf("%lld\n",m);
}