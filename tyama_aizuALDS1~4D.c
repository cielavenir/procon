int a[100000];
int ok(int M,int N,int C){
	int sum=0,ret=1,i=0;
	for(;i<N;i++){
		if(a[i]>M)return 0;
		sum+=a[i];
		if(sum>M)sum=a[i],ret++;
	}
	return ret<=C;
}
main(){
	int N,C,i=0;
	scanf("%d%d",&N,&C);
	for(;i<N;i++)scanf("%d",a+i);
	int l=0,h=1LL<<30;
	for(;l+1<h;){
		int m=(l+h)/2;
		if(ok(m,N,C))h=m;else l=m;
	}
	printf("%d\n",l+1);
	exit(0);
}