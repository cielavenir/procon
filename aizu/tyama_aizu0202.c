#define M 1000001
T[M],t[M],a;main(m,n,x,i,j){
	for(i=2;i<M;i++)if(!T[i])for(j=i*2;j<M;j+=i)T[j]=1;
	for(;scanf("%d%d",&n,&x),n;printf(m?"%d\n":"NA\n",m))
		for(memset(t,0,sizeof(t)),t[0]=1,m=i=0;i<n;i++)
			for(scanf("%d",&a),j=0;j+a<=x;j++)if(t[j])if(t[j+a]=1,!T[j+a]&&m<j+a)m=j+a;
exit(0);}