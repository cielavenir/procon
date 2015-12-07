int memo[8000008],n;
int dfs(int k,int p,int d){
	if(k<0||p<0)return 0;
	if(d==0)return 1;
	auto x=(d<<3)|(k<<1)|p;
	if(memo[x])return memo[x];
	return memo[x]=(dfs(k-1,1,d-1)+dfs(2,p-1,d-1))%1000000007;
}
main(){
	scanf("%d",&n);
	n=!printf("%d\n",dfs(2,0,n));
}