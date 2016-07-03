T[10001],A[10001],B[99],k,r;main(){
	int m,n,i,j;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)scanf("%d",B+i),A[B[i]]=1;
	for(i=0;i<n;i++)for(j=0;j<=m-B[i];j++)if(A[j]&&A[j+B[i]]<=A[j])A[j+B[i]]=A[j]+1;
	for(i=2;i<=m;i++)if(k=k>A[i]?k:A[i],!T[i])for(r+=A[m-i],j=i;j<=m;j+=i)T[j]=1;
	*B=!printf("%lld\n",r+k);
}