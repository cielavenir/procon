#define M 9999
T[M]={1,1};main(i,j){
	for(i=2;i<M;i++)if(!T[i])for(j=i*2;j<M;j+=i)T[j]=1;
	for(;~scanf("%d",&j);puts(""))for(printf("2"),i=3;i<j;i+=2)if(!T[i])printf(",%d",i);
}