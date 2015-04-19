#define M 1000000
a[M+1];
main(i,x){
	a[0]=1;
	for(x=1;x<=M;x*=2)for(i=0;i+x<=M;i++)a[i+x]=(a[i+x]+a[i])%1000000000;
	scanf("%d",&x),printf("%d\n",a[x]);
}