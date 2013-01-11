v[1001];main(n,d,i,j,r){for(;~scanf("%d%d",&n,&d);printf("%d\n",r)){
	v[0]=2,v[1]=3;for(i=2;i<n;i++)v[i]=(v[i-2]+v[i-1])%1001;
	for(i=0;i<n;i++)for(j=0;j<n-i-1;j++)if(v[j]>v[j+1])r=v[j],v[j]=v[j+1],v[j+1]=r;
	for(i=r=1;i<n;i++)if(v[i]-v[i-1]>=d)r++;
}exit(0);}