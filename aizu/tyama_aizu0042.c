t[999];main(T,W,N,w,c,i,j,m){for(;scanf("%d%d",&W,&N)>1;printf("Case %d:\n%d\n%d\n",T++,m-1,i)){
for(memset(t,0,sizeof(t)),t[0]=1,i=0;i<N;i++)
	for(scanf("%d,%d",&c,&w),j=W;j>=0;j--)if(t[j])if(t[j+w]<t[j]+c)t[j+w]=t[j]+c;
for(m=j=0;j<=W;j++)if(m<t[j])m=t[j],i=j;
}exit(0);}