main(){
	int n,a,b,r;
	for(scanf("%d",&n);n--;){
		scanf("%d%d",&a,&b);
		if(a-b!=2&&a-b!=0)puts("No Number");
		else printf("%d\n",b/2*4+b%2+(a-b));
	}
}