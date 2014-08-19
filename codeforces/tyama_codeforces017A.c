#define M 999
a[M+1];x[M+1];b[200];
main(i,j){
	for(i=3;i<=M;i+=2)if(!a[i])for(j=i*2;j<=M;j+=i)a[j]=1;
	for(j=1,i=3;i<=M;i+=2)if(!a[i])b[j++]=i;
	for(i=1;;i++)if((j=b[i]+b[i+1]+1)>M)break;else if(!a[j])x[j]=1;
	scanf("%d%d",&i,&j);
	for(;i;)if(x[i--])j--;
	puts(j>0?"NO":"YES");
	return 0;
}