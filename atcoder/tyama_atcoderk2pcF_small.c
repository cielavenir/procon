#define M 100000
main(){
	int k,r;
	scanf("%d%d",&k,&r);
	if(!r){
		int a=1,b=0,c=0,t;
		for(;k;k--)t=(a+b+c)%M,b=(a+b)%M,c=(a+c)%M,a=t;
		printf("%d\n",a);
	}
	exit(0);
}