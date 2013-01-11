#define M 1000001
T[M];long long p[M],a[M];
main(i,j){
for(i=0;i<M;i++)p[i]=i;
for(i=2;i<M;i++)if(!T[i])for(p[i]-=p[i]/i,j=i*2;j<M;j+=i)T[j]=1,p[j]-=p[j]/i;
for(i=1;i<M;i++)a[i]=a[i-1]+p[i];
//for(scanf("%d",&i);i;i--)scanf("%d",&j),printf("%lld\n",a[j]+1); //aizu2286
for(;scanf("%d",&j),j;)printf("%lld\n",a[j]-1); //PKU2478
exit(0);}