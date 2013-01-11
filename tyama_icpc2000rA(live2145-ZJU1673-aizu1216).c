double d[3],e[3],s[99][3];main(T,n,i,j,k,l){for(scanf("%d",&T);T;T--){
for(scanf("%lf%lf%lf%d",d,d+1,d+2,&n),i=0;i<n;i++)scanf("%lf%lf%lf",s[i],s[i]+1,s[i]+2);
for(i=0;i<n;i++)for(j=0;j<n;j++)for(*e=sqrt(pow(*s[j]-*s[i],2)+pow(s[j][1]-s[i][1],2)+pow(s[j][2]-s[i][2],2)),k=0;k<n;k++)if(i-j&&j-k&&k-i){
	e[1]=sqrt(pow(*s[k]-*s[j],2)+pow(s[k][1]-s[j][1],2)+pow(s[k][2]-s[j][2],2));
	e[2]=sqrt(pow(*s[i]-*s[k],2)+pow(s[i][1]-s[k][1],2)+pow(s[i][2]-s[k][2],2));
	for(l=0;l<3;l++)if(d[l]/d[(l+1)%3]-e[l]/e[(l+1)%3]>1e-3)break;
	if(l>2)printf("%d %d %d\n",k+1,i+1,j+1);
}
}exit(0);}