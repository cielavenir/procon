int a[501];
main(i,n,q,s){
  scanf("%d%d",&n,&q);
  for(;i<=n;i++)scanf("%d",a+i);
  for(;q;printf("%d\n",s),q--)
    for(scanf("%d%d",&i,&n),s=0;i<=n;i++)s+=a[i];
}