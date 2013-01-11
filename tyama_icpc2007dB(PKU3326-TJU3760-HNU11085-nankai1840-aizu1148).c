int M[10000][720],C[10000],T[10000];
int main(r,q,t,u,m,s){
	for(;scanf("%d%d",&r,&q),r;){
		memset(M,0,7200000*4);
		memset(T,0xff,10000*4);
		for(scanf("%d",&r);r;r--){
			scanf("%d%d%d%d",&t,&m,&m,&s);
			if(T[m]==-1)T[m]=t-540;
			if(s)C[m]++;
			else{
				C[m]--;
				if(!C[m]){
					for(q=T[m];q<t-540;q++)M[m][q]=1;
					T[m]=-1;
				}
			}
		}
		for(scanf("%d",&q);q;q--){
			scanf("%d%d%d",&t,&u,&m);
			for(r=0;t<u;t++)
				if(M[m][t-540])r++;
			printf("%d\n",r);
		}
	}
	return 0;
}