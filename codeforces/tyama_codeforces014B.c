main(m,M,n,x,a,b,t){
  for(M=1000,m=0,scanf("%d%d",&n,&x);n--;){
    scanf("%d%d",&a,&b);
    if(a>b)t=a,a=b,b=t;
    if(a>m)m=a;
    if(b<M)M=b;
  }
  if(m>M){printf("-1\n");return 0;}
  if(m<=x&&x<=M){puts("0\n");return 0;}
  printf("%d\n",(a=abs(M-x))<(b=abs(x-m))?a:b);
  return 0;
}