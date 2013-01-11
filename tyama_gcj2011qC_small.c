a[1000];main(t,T,n,N,r,i,j,S,P1,P2){
	for(t=1,scanf("%d",&T);t<=T;printf("Case #%d: ",t),printf(r?"%d\n":"NO\n",r),t++){
		for(r=n=0,scanf("%d",&N);n<N;n++)scanf("%d",a+n);
		for(i=1;i<(1<<N)-1;i++){ //brute force for small O(N*2^N).
			for(S=P1=P2=j=0;j<N;j++){
				if(i&(1<<j)){
					P1^=a[j];
				}else{
					P2^=a[j],S+=a[j];
				}
			}
			if(P1==P2&&r<S)r=S;
		}
	}
}