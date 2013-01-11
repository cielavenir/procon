#define M 300000
int T[M];
main(i,j,r){
	for(T[0]=T[1]=1,i=2;i<M;i++)
		if(!T[i])
			for(j=2*i;j<M;j+=i)T[j]=1;
	for(;scanf("%d",&i),i;printf("%d\n",r))
		for(r=0,j=i+1;j<=2*i;j++)
			if(!T[j])r++;
exit(0);}