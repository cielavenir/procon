main(n,b,h,w,p,a,m,i,f){
  for(f=scanf("%d%d%d%d",&n,&b,&h,&w);h;h--){
    scanf("%d",&p);
    for(m=i=0;i<w;i++)scanf("%d",&a),m=m<a?a:m;
    if(p*n<=b&&n<=m)b=p*n,f=0;
  }
  printf(f?"stay home":"%d",b);
}