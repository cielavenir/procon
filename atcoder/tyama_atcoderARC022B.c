int last[100001],a[100001];
main(){
	int r=0,d,z=0,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",a+i);
	for(i=0;i<=n;i++){
		d=i-z;
		if(r<d)r=d;
		if(z<last[a[i]])z=last[a[i]];
		last[a[i]]=i+1;
	}
	printf("%d\n",r);
	exit(0);
}