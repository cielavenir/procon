b[2000];main(n,d,i,r){
  for(scanf("%d%d",&n,&d),i=r=0;i<n;i++)scanf("%d",b+i);
  for(i=1;i<n;i++){
    for(;b[i-1]-b[i]>=1000*d;r+=1000)b[i]+=1000*d;
    for(;b[i-1]-b[i]>=100*d;r+=100)b[i]+=100*d;
    for(;b[i-1]-b[i]>=10*d;r+=10)b[i]+=10*d;
    for(;b[i-1]-b[i]>=0;r++)b[i]+=d;
  }
  printf("%d\n",r);
  return 0;
}