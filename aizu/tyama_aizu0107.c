main(a,b,c,n,r){
  for(;scanf("%d%d%d%d",&a,&b,&c,&n),a;){
    if(a>c)r=a,a=c,c=r;
    if(b>c)r=b,b=c,c=r;
    for(;n--;puts(r*2>hypot(a,b)?"OK":"NA"))scanf("%d",&r);
  }
  exit(0);
}