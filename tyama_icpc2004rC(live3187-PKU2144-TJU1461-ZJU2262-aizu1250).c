a[9];main(t,i,j,k,x){for(scanf("%d",&t);t--;printf("%x\n",k)){
	for(i=0;i<9;i++)scanf("%x",a+i);
	for(k=j=0;j<32;k|=(x^a[8])&(1<<j++))for(x=i=0;i<8;i++)x+=a[i]^k;
}exit(0);}