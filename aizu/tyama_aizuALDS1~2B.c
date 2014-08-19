a[999],t,i,j,c,r;main(n){
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	for(i=0;i<n;i++){
		for(c=i,j=i+1;j<n;j++)if(a[j]<a[c])c=j;
		if(c>i)t=a[i],a[i]=a[c],a[c]=t,r++;
	}
	for(i=0;i<n;i++)printf(i<n-1?"%d ":"%d\n",a[i]);
	printf("%d\n",r);
	exit(0);
}