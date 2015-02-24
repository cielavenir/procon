a[1000],m,n,c;main(d){
for(scanf("%d%d",&n,&m);m--;)for(scanf("%d%d",&c,&d);c<d;c++)a[c]=1;
for(c=d=0;c<n;c++)d+=a[c]*2;
m=!printf("%d\n",d+n+1);
}