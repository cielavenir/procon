long long M[10][1001];
main(i,j,k){
	M[0][0]=1;
	for(i=0;i<=100;i++)for(j=1000;j-i>=0;j--)for(k=9;k;k--)M[k][j]+=M[k-1][j-i];
	for(;scanf("%d%d",&i,&j),i|j;)printf("%lld\n",M[i][j]);
exit(0);}