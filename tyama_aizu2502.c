#define M 393
i,j,d[M+1],phrase[M+1],r[M];
main(n,m,s,l,p){
	for(scanf("%d",&n);i<n;i++)for(scanf("%d%d%d",&s,&l,&p);s<=l;s++)if(phrase[s]<p)phrase[s]=p;
	for(i=1;i<=M;i++)d[i]=-1;
	for(i=1;i<=M;i++)if(phrase[i])for(j=0;j+i<=M;j++)if(d[j]>=0&&d[j+i]<d[j]+phrase[i])d[j+i]=d[j]+phrase[i];
	for(scanf("%d",&m),i=0;i<m;r[i++]=d[s])if(scanf("%d",&s),d[s]<0)exit(!puts("-1"));
	for(i=0;i<m;i++)printf("%d\n",r[i]);
exit(0);}