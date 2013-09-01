#define M 10000
a[100],m[M+1],n;
main(){
	int i,j;
	for(scanf("%d",&n),i=0;i<n;i++)scanf("%d\n",a+i);
	m[0]=1;
	for(i=0;i<n;i++)for(j=M;j>=a[i];j--)m[j]|=m[j-a[i]];
	for(i=j=0;i<=M;i++)j+=m[i];
	printf("%d\n",j);
	exit(0);
}