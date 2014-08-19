int a[100010],b[100010];
main(n,m,c,i,j,s,o,p){
	scanf("%d%d%d",&n,&m,&c);
	for(i=0;i<n;i++)scanf("%d",a+i);
	for(i=0;i<m;i++)scanf("%d",b+i);
#if 0
	for(i=0;i<n-m+1;i++)
		for(j=0;j<m;j++)
			a[i+j]=(a[i+j]+b[j])%c;
#else
	for(s=o=p=i=0;i<n;i++){
		if(i<m){
			s+=b[o];
			//printf("add %d %d\n",b[o],o); //add = m
			o++;
		}
		if(i+m>n){
			s-=b[p];
			//printf("sub %d %d\n",b[x],x); // sub = m-1
			p++;
		}
		a[i]=(a[i]+s)%c;
		//printf("---%d %d\n",o,s);
	}
#endif
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		putchar(i==n-1?'\n':' ');
	}
	exit(0);
}