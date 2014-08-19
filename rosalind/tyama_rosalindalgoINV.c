a[99999],i,j,n,x;
main(){
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	for(x=i=0;i<n;i++)for(j=i+1;j<n;j++)x+=a[i]>a[j];
	printf("%d\n",x);
}