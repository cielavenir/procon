a[300001],m[300001];
main(){
	int N,K,i,r;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++)scanf("%d",a+i);
	for(m[0]=i=r=1;i<N;i++)m[i]=a[i-1]<a[i]?++r:(r=1);
	for(i=r=0;i<N;i++)r+=K<=m[i];
	printf("%d\n",r);
	exit(0);
}