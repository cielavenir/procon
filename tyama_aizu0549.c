a[99999],x,r;main(n,m){
for(scanf("%d%d",&n,&m);++x<n;a[x]+=a[x-1])scanf("%d",a+x);
for(n=0;m;m--)scanf("%d",&x),r=(r+abs(a[n+x]-a[n]))%100000,n+=x;
x=!printf("%d\n",r);}