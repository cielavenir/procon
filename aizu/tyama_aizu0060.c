z[11];main(a,b,c,r){for(;~scanf("%d%d%d",&a,&b,&c);puts(r>4?"YES":"NO")){
	memset(z,1,sizeof(z));z[a]=z[b]=z[c]=0;a+=b;
	for(r=0,b=1;b<11;b++)if(z[b]&&a+b<21)r++;
}exit(0);}