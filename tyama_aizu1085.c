N[101];main(i,j,n,S){
	for(;scanf("%d%d",&n,&S),n;printf("%d\n",n)){
		for(memset(N,0,404),i=0;i<n;i++)scanf("%d",&j),N[j]++;
		for(n=0,i=101;i>0;i--)if(N[i]){
				if(i*2>S)n+=N[i]*(N[i]-1)/2;
				for(j=i-1;j>0&&i+j>S;j--)n+=N[i]*N[j];
		}
	}
	return 0;
}