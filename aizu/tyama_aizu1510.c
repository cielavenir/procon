char M[7][7][7],m[7][7][7];A,a[99],B,b[99],T;
main(n,s,i,j,k,I,J,K){for(;scanf("%d",&n),n;){
	if(T)puts("");
	for(i=1;i<6;i++)for(j=1;j<6;j++)for(scanf("%s",M[i][j]+1),k=1;k<6;k++)M[i][j][k]-='0';
	for(scanf("%d",&A),i=0;i<A;i++)scanf("%d",a+i);
	for(scanf("%d",&B),i=0;i<B;i++)scanf("%d",b+i);
	for(;n--;memcpy(M,m,sizeof(M))){
		for(i=1;i<6;i++)for(j=1;j<6;j++)for(k=1;k<6;k++){
			m[i][j][k]=M[i][j][k];
			for(s=0,I=-1;I<2;I++)for(J=-1;J<2;J++)for(K=-1;K<2;K++)if((I||J||K)&&M[i+I][j+J][k+K])s++;
			if(m[i][j][k]){
				for(I=0;I<B;I++)if(s==b[I])break;
				if(I==B)m[i][j][k]=0;
			}else{
				for(I=0;I<A;I++)if(s==a[I])break;
				if(I<A)m[i][j][k]=1;
			}
		}
	}
	printf("Case %d:\n",++T);
	for(i=1;i<6;printf(i<5?"\n":""),i++)for(j=1;j<6;puts(""),j++)for(k=1;k<6;k++)putchar(M[i][j][k]+'0');
}exit(0);}