F[501][501];
main(m,n,w,h,s,t,i,j,k,l){for(;scanf("%d",&n),n;printf("%d\n",n)){
	for(scanf("%d%d",&w,&h),memset(F,0,sizeof(F)),i=0;i<n;i++)scanf("%d%d",&k,&l),F[k][l]=1;
	for(scanf("%d%d",&s,&t),n=i=0;i<=w-s+1;i++)for(j=0;j<=h-t+1;n=n>m?n:m,j++)for(m=0,k=i;k<i+s;k++)for(l=j;l<j+t;l++)if(F[k][l])m++;
}}