a[100001]; //need segment tree here...
int gcd(int x,int y){return y?gcd(y,x%y):x;}
main(){
	int N,M,i,t,l,r;
	scanf("%d",&N);
	for(i=1;i<=N;i++)scanf("%d",a+i);
	scanf("%d",&M);
	for(i=0;i<M;i++){
		scanf("%d%d%d",&t,&l,&r);
		if(t==0){
			int g=a[l];
			for(;l<=r;l++)g=gcd(g,a[l]);
			printf("%d\n",g);
		}else{
			for(;l<=r;l++)a[l]+=t;
		}
	}
	exit(0);
}