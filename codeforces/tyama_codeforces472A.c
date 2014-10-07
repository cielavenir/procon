#define M 1000000
int a[M+1]={1,1};
main(n,i,j){
	for(i=2;i<=M;i++)if(!a[i])for(j=i*2;j<=M;j+=i)a[j]=1;
	scanf("%d",&n);
	for(i=2;i<=M;i++)if(a[i]&&a[n-i]){
		printf("%d %d\n",i,n-i);
		break;
	}
	exit(0);
}