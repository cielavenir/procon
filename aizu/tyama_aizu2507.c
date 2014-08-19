a[99]={1,4,12,38};main(i,n,m){scanf("%d%d",&n,&m);
	if(m==1)for(;i<101;i++)a[i]=2*a[i-1]%1000000;
	else for(i=4;i<101;i++)a[i]=(4*a[i-1]-3*a[i-2]+2*a[i-3]+a[i-4]+3000000)%1000000;
	printf("%d\n",a[n]);exit(0);
}