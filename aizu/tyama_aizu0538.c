char s[1000001];c[1000001];
main(n,m,i,r){for(;~scanf("%d",&n)&&n;printf("%d\n",r)){
	for(memset(c,0,sizeof(c)),scanf("%d%s",&m,s),i=2;i<m;i++)if(s[i-2]=='I'&&s[i-1]=='O'&&s[i]=='I')c[i]=c[i-2]+1;
	for(i=r=0;i<m;i++)if(c[i]>=n)r++;
}}
