int visit[1000];
int m[1000][1000];
int n;
int D(int parent,int node){
	int i;
	if(visit[node])return 0;
	visit[node]=1;
	for(i=1;i<=n;i++){
		if(m[node][i]){
			if(visit[i]&&parent!=i)return 1;
			if(!visit[i]&&D(node,i))return 1;
		}
	}
	return 0;
}
int main(){
	int i,j,M,s,t;
	scanf("%d%d",&n,&M);
	for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)m[i][j]=m[j][i]=1;
	for(;M;M--){
		memset(visit,0,sizeof(visit));
		scanf("%d%d",&s,&t);
		m[s][t]^=1,m[t][s]^=1;
		for(i=1;i<=n;i++)if(D(-1,i))break;
		puts(i>n?"yes":"no");
	}
	exit(0);
}