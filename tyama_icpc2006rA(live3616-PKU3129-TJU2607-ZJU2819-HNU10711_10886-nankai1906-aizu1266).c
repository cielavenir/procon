double s[999][3],t[3],p,d,n1,n2;r[999];main(n,m,i,j){for(;scanf("%d",&n),n;printf("%d\n",m)){
for(i=0;i<n;i++)scanf("%lf%lf%lf",s[i],s[i]+1,s[i]+2);
for(memset(r,0,sizeof(r)),scanf("%d",&m),j=0;j<m;j++)
	for(scanf("%lf%lf%lf%lf",t,t+1,t+2,&p),n2=sqrt(t[0]*t[0]+t[1]*t[1]+t[2]*t[2]),i=0;i<n;i++)
		if(n1=sqrt(s[i][0]*s[i][0]+s[i][1]*s[i][1]+s[i][2]*s[i][2]),d=t[0]*s[i][0]+t[1]*s[i][1]+t[2]*s[i][2],acos(d/n1/n2)<p)r[i]=1;
for(m=i=0;i<n;i++)m+=r[i];
}exit(0);}