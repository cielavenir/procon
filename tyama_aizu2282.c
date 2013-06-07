main(n,m,i,I,j,J,a,A,c){
for(;scanf("%d %d",&n,&m),n;printf("%d\n",c<2?I:n))for(J=1e9,i=0;i<n;i++)
	if(scanf("%d",&a),j=m-m%a,j<J||(j==J&&a<=A))c=j==J&&a==A?c+1:1,J=j,A=a,I=i+1;
exit(0);}