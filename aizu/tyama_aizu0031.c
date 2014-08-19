main(f,n,x){
  for(;~scanf("%d",&n);puts("")){
    for(f=0,x=1;n;x+=x){
      if(n&x){
        if(f)putchar(' ');
        printf("%d",x),n-=x,f=1;
      }
    }
  }
  return 0;
}