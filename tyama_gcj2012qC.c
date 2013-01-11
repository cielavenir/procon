main(){
	int t=1,T,p,q,r,a,b,l,L,n,m;
	for(scanf("%d",&T);t<=T;printf("Case #%d: %d\n",t++,r)){
		scanf("%d%d",&a,&b);
		for(n=a,l=10;n/10;n/=10)l*=10;
		for(n=a,r=0;n<=b;n++){
			for(p=q=0,L=1;L<l;L*=10){
				m=(n%L)*(l/L)+n/L;
				if(n==m)p++;
				if(n<m&&m<=b)q++;
			}
			r+=q/p;
		}
	}
}