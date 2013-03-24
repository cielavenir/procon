o[256],z[256];main(N,S,A,C,s,a,c,r,i){for(;scanf("%d",&N),N;printf("%d %d %d\n",S,A,C)){
	double H=9,h,n=N;
	for(i=0;i<N;i++)scanf("%d",z+i);
	for(s=0;s<16;s++)for(a=0;a<16;a++)for(c=0;c<16;c++){
		for(r=s,i=0;i<N;)o[z[i++]+(r=(a*r+c)&255)&255]++;
		for(h=i=0;i<256;i++)if(o[i])h-=o[i]/n*log(o[i]/n),o[i]=0;
		if(h+1e-9<H)H=h,S=s,A=a,C=c;
	}
}exit(0);}