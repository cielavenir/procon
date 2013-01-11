a[9999];main(n,i,j,m,s){for(;scanf("%d",&n),n;printf("%d\n",m)){
for(i=0;i<n;i++)scanf("%d",a+i);
for(m=-999999,i=0;i<n;i++)for(s=0,j=i;j<n;m=m>s?m:s,j++)s+=a[j];
}exit(0);}