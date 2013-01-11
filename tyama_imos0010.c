int a[100000];
main(n,r,i){
  for(;scanf("%d",&n),n;printf("%d\n",r)){
    memset(a,0,sizeof(a));
    for(;n;n--){
      scanf("%d",&i);
      a[i]=1;
    }
    if(!a[1]){r=1;goto next;}
    for(i=2;i<100000;i++)
      if(a[i]){
        int d=i-1;
        if(!(d%2)&&a[i+d/2]){
          r=1+d/2;
        }else{
          for(;a[i];i+=d);
          r=i;
        }
        goto next;
      }
    next:;
  }
  return 0;
}