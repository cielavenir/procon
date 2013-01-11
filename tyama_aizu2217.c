m[10000],c[10000];
int D(n){if(c[n]>=0)return c[n];c[n]=1;int r=D(m[n]);c[n]=0;return r;}
main(n,x,y,r,s){for(;scanf("%d",&n),n;printf("%d\n",r)){
	memset(c,255,sizeof(m));
	for(y=0;y<n;y++)for(x=0;x<n;x++)scanf("%d%d",&r,&s),m[y*n+x]=s*n+r;
	for(r=x=0;x<n*n;x++)r+=D(x);
}exit(0);}