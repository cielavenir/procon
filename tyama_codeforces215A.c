A[50],B[50],i,j,M;main(r,n,m,d){
	for(scanf("%d",&n);i<n;i++)scanf("%d",A+i);
	for(scanf("%d",&m);j<m;j++)scanf("%d",B+j);
	for(i=0;i<n;i++)for(j=0;j<m;j++)if(B[j]%A[i]==0)if((d=B[j]/A[i])>M)M=d,r=1;else if(d==M)r++;
	i=!printf("%d\n",r);
}