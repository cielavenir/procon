main(i,t,n,m){for(scanf("%d",&t);t--;printf("%d %d\n",i,m)){
	scanf("%d%d",&i,&n);
	for(m=n;n!=1;m=n>m?n:m)n=n%2?n*3+1:(n/2);
}}