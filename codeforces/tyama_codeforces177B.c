#define MAX 32000
prime[MAX];
main(i,j,n,c,x){
	for(i=2;i<MAX;i++)
		if(!prime[i])
			for(j=i*2;j<MAX;j+=i)
				prime[j]=1;
	scanf("%d",&n);
	for(c=n;n>1;){
		for(x=2;x<MAX;x++){
			if(!prime[x]&&n%x==0){
				c+=n/x;
				n/=x;
				goto next;
			}
		}
		if(x==MAX)break;
		next:;
	}
	printf("%d\n",c+(n>1?1:0));
	exit(0);
}