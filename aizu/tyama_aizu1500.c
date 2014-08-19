a[10],m;
int D(s,x1,x2){
	int r=0,i=0;
	for(;i<m;i++)
		if(x1)r+=D(s+a[i],x1-1,x2);
		else if(x2)r+=D(s+a[i]/5+a[i]%5*2,x1,x2-1);
		else return s%10==0;
	return r;
}
main(i,j,n,c,s,x1,x2){
	scanf("%d",&n);getchar();
	for(s=x1=x2=i=0;i<n;i++)
		if(c=getchar()-48,(n-i)&1)//odd position from right
			if(c==-6)x1++;else s+=c;
		else
			if(c==-6)x2++;else s+=c/5+c%5*2;
	for(scanf("%d",&m),i=0;i<m;i++)scanf("%d\n",a+i);
	printf("%d\n",D(s,x1,x2));
	exit(0);
}