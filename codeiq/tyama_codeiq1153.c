int dfs(long long x,long long y){return y?dfs(y,x%y)+1:0;}
int main(){
	long long N,i,j,mai,maj;
	int ma=0;
	scanf("%lld",&N);
	for(i=1;i<=N;i++){
		for(j=1;j<=i;j++){
			int x=dfs(i,j);
			if(ma<x)ma=x,mai=i,maj=j;
		}
	}
	printf("%d %lld %lld\n",ma,mai,maj);
	return 0;
}