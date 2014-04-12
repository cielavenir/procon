main(){
	unsigned short n,m,x=0,i=0;
	scanf("%hu%hu",&n,&m);
	for(;;){
		x+=i;
		if(i==n)break;
		i+=m;
		if(!i)break;
	}
	printf("%hu\n",x);
	return 0;
}