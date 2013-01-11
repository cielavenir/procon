#define M 32768
p[M+1];main(i,j,n){p[1]=1;for(;i<=M;i++)if(!p[i])for(j=i*2;j<=M;j+=i)p[j]=1;for(;scanf("%d",&n),n;printf("%d\n",j))for(i=2,j=0;i<=n/2;i++)if(!p[i]&&!p[n-i])j++;exit(0);}