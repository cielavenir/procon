a[999],t,i,j,r;main(n){
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	for(i=0;i<n;i++)for(j=0;j<n-i-1;j++)if(a[j]>a[j+1])t=a[j],a[j]=a[j+1],a[j+1]=t,r++;
	for(i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",a[i]);
	printf("%d\n",r);
	exit(0);
}