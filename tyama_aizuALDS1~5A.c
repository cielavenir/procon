a[20],m[9999],i,j;main(n,s){
for(scanf("%d",&n),i=0;i<n;i++)scanf("%d",a+i);
for(i=0;i<1<<n;s<9999?m[s]=1:0,i++)for(s=j=0;j<n;j++)if(i&(1<<j))s+=a[j];
for(scanf("%d",&n);n--;puts(m[s]?"yes":"no"))scanf("%d",&s);
exit(0);}