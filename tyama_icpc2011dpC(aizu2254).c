#define min(a,b) ((a)<(b)?(a):(b))
#define M 16
int m[M][M+1];
int a[1<<M];
int main(){
	int N,i,j,k;
	for(;scanf("%d",&N),N;printf("%d\n",a[(1<<N)-1])){
		for(i=0;i<N;i++)for(j=0;j<=N;j++)scanf("%d",m[i]+j);
		for(i=1;i<1<<N;i++)a[i]=1<<30;
		for(i=0;i<1<<N;i++)for(j=0;j<N;j++)if(((i>>j)&1)==0){
			int x=m[j][0];
			for(k=0;k<N;k++)if(((i>>k)&1)!=0)x=min(x,m[j][k+1]);
			a[i|(1<<j)]=min(a[i|(1<<j)],a[i]+x);
		}
	}
	return 0;
}