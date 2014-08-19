#define M 51000
n[M];main(i,j){n[0]=n[1]=1;for(i=2;i<M;i++)if(!n[i])for(j=i*2;j<M;j+=i)n[j]=1;for(;~scanf("%d",&i);printf("%d %d\n",i,j)){for(j=i+1,i--;n[i];i--);for(;n[j];j++);}exit(0);}