a[25];main(n,i,p){for(;scanf("%d",&n),n;puts("0")){
	for(i=0;i<n;i++)scanf("%d",a+i);
	for(puts("31"),i=0,p=31;p>1;printf("%d\n",p-=(p-1)%5))printf("%d\n",p-=a[i++%n]);
}exit(0);}