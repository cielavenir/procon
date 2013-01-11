#define M 99999
T[M],t[M];main(I,i,j,m,a,b,p,q){
for(i=2;i<M;i++)if(!T[i])for(j=i*2;j<M;j+=i)T[j]=1;
for(i=2,j=1;i<M;i++)if(!T[i])t[j++]=i;
for(;scanf("%d%d%d",&m,&a,&b),m;printf("%d %d\n",p,q))for(i=1;I=t[i];i++)if(I*I>m)i=0,m--;else if(!T[q=m/I]&&(p=I)*q==m&&a*q<=b*p)break;
exit(0);}