#define M 100
int a[M+1];long long r;
int main(){
	int N,x,i,j,k;
	for(scanf("%d",&N);N--;)scanf("%d",&x),a[x]++;
	for(i=1;i<=M-2;i++)for(j=i+1;j<=M-1;j++)for(k=j+1;k<=M;k++){
		r+=a[i]*a[j]*a[k];
	}
	printf("%lld\n",r%1000000007);
}