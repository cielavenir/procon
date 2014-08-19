a[99],b[99];main(i,n){for(;scanf("%d",&n),n;){
	for(i=0;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	if(b[1]==b[2]&&b[2]==b[3]&&b[3]==b[4]){
		for(i=5;i<=n;i++)if(b[i]!=b[1])break;
		printf("%d\n",a[i]);
	}
	else if(b[2]==b[3]&&b[3]==b[4])printf("%d\n",a[0]);
	else if(b[1]==b[2]&&b[2]==b[3])printf("%d\n",a[4]);
	else if(a[2]-a[0]==b[3]&&b[3]==b[4])printf("%d\n",a[1]);
	else if(b[1]==b[2]&&b[2]==a[4]-a[2])printf("%d\n",a[3]);
	else if(b[1]==a[3]-a[1]&&b[1]==b[4])printf("%d\n",a[2]);
	else exit(1);
}exit(0);}