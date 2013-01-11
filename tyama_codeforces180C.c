char a[110000];
//int u[110000];
int d[110000];
main(i,z,x){
	scanf("%s",a);
	for(z=0,i=strlen(a)-1;i>=0;d[i]=z,i--)
		if('A'<=a[i]&&a[i]<='Z')z++;
#if 0
	for(z=i=0;i<strlen(a);u[i]=z,i++)
		if('a'<=a[i]&&a[i]<='z')z++;
	for(z=d[0],i=0;i<strlen(a);i++)
		if(u[i]+d[i+1]<z)z=u[i]+d[i+1];
#else
	for(x=0,z=d[0],i=0;i<strlen(a);i++){
		if('a'<=a[i]&&a[i]<='z')x++;
		if(x+d[i+1]<z)z=x+d[i+1];
	}
#endif
	printf("%d\n",z);
	exit(0);
}