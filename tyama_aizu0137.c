main(c,i,x){
  for(scanf("%d",&x);~scanf("%d",&x);c++)
    for(printf("Case %d:\n",c),i=0;i<10;i++)
      printf("%d\n",x=x*x/100%10000);
  return 0;
}