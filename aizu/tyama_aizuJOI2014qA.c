main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	a*=e;
	if(c<e)b+=d*(e-c);
	if(a>b)a=b;
	printf("%d\n",a);
	return 0;
}