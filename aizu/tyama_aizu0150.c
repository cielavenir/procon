#define M 10001
n[M];main(i,j){n[0]=n[1]=1;for(i=2;i<M;i++)if(!n[i])for(j=i*2;j<M;j+=i)n[j]=1;for(;scanf("%d",&i),i;printf("%d %d\n",i-2,i))for(;n[i-2]||n[i];i--);exit(0);}