char s[1001],*S="JOI";
int N,n,M[1000][8];
int dfs(d,prev){
	if(d==N)return 1;
	if(M[d][prev])return M[d][prev];
	int i=1,r=0;
	for(;i<8;i++)if((s[d]&i)&&(prev&i))r=(r+dfs(d+1,i))%10007;
	return M[d][prev]=r;
}
main(){
	scanf("%d%s",&N,s);
	for(;n<N;n++)s[n]=1<<(strchr(S,s[n])-S);
	n=!printf("%d\n",dfs(0,1));
}