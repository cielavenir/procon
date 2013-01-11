m[5][5];main(T,i,j,k,r,M,z){
for(scanf("%d",&T);T;printf("%d\n",r),T--){
	for(j=0;j<5;j++)for(r=i=0;i<5;m[j][i]=r,i++)if(scanf("%d",&k),k)r++;else r=0;
	for(r=i=0;i<5;i++)for(j=0;j<5;j++)for(M=9,k=j;k<5;k++){
		if(M>m[k][i])M=m[k][i];
		if(r<M*(z=k-j+1))r=M*z;
	}
}exit(0);}