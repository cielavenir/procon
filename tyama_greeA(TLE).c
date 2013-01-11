//#define LIMIT 50000
main(N,n,k,i,j,r,_k,_n){
	for(scanf("%d",&N);N--;printf("%d\n",r)){
		scanf("%d%d",&n,&k);
		i=r=0,_k=k-1,_n=n/k;
		do{
			j=i/k;
			i=(_k-i+j*k)*_n+j;
			r++;
		}while(i!=0&&i!=n-1/*&&r<LIMIT*/);
		//if(r==LIMIT)r=-1;
		if(i==n-1)r*=2;
	}
	exit(0);
}