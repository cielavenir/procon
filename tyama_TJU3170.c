int a[10001];
main(N,n,q,i,v){
  scanf("%d%d",&n,&q);
  for(i=0;n;n--,N++)
    for(scanf("%d",&v);v;v--,i++)a[i]=N;
  for(;q;q--)scanf("%d",&i),printf("%d\n",a[i]);
}