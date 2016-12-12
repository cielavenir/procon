a[99999],T[99999],n,e;main(i){
	for(*a=scanf("%d",&n),e=2;e<=n;e++)if(!T[e]){
		for(i=e+e;i<=n;i+=e)T[i]=1;
		for(i=n;i>=e;i--)if(a[i-e]&&a[i]<a[i-e]+1)a[i]=a[i-e]+1;
	}
	n=!printf("%d\n",a[n]-1);
}
