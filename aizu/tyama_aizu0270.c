#define M 300001
a[M],i;main(n,q,x){
for(scanf("%d%d",&n,&q);i<n;i++)scanf("%d",&x),a[x]=x;
for(i=1;i<M;i++)if(!a[i])a[i]=a[i-1];
for(;q--;printf("%d\n",n))if(n=0,scanf("%d",&x),x>1)for(i=x;i<=M;i+=x)if(n<a[i-1]%x)n=a[i-1]%x;
exit(0);}