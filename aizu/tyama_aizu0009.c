#define M 1000000
n[M];main(i,j){n[0]=0;n[1]=-1;for(i=2;i<M;i++)if(!n[i])for(j=i*2;j<M;j+=i)n[j]=-1;for(i=1;i<M;i++)n[i]+=n[i-1]+1;for(;~scanf("%d",&i);printf("%d\n",n[i]));exit(0);}