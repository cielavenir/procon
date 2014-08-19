char a[500][501];m[500][500];main(i,j,k,x,y,r,M,z){
for(;scanf("%d%d",&y,&x),x;printf("%d\n",r)){
	for(j=0;j<y;j++)scanf("%s",a[j]);
	for(j=0;j<y;j++)for(r=i=0;i<x;m[j][i]=r,i++)if(a[j][i]=='.')r++;else r=0;
	for(r=i=0;i<x;i++)for(j=0;j<y;j++)for(M=99,k=j;k<y;k++){
		if(M>m[k][i])M=m[k][i];
		if(r<M*(z=k-j+1))r=M*z;
	}
}exit(0);}