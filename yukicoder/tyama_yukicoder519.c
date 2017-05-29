r[1<<24],m[24][24],n,j,s,u;main(i,k,t){
	for(scanf("%d",&n);j<n;j++)for(i=0;i<n;i++)scanf("%d",m[j]+i);
	for(i=0;i<1<<n;i++)if(!__builtin_parity(i))for(j=__builtin_ctz(~i),u=i|1<<j,k=j+1;k<n;k++)if(t=u|1<<k,t!=u&&r[t]<(s=r[i]+m[j][k]))r[t]=s;
	printf("%d\n",r[(1<<n)-1]);
}
