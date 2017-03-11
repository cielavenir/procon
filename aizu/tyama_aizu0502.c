main(i,n,x,a,b,c,p,q,r){
  char s[6];
  for(;~scanf("%d",&n)&&n;printf("%d\n",x)){
    for(x=1,a=1,b=2,c=3,i=0;i<n;i++){
      scanf("%s",s);
      switch(*s){
        case 'L':
          p=a,  q=7-c,r=b;   break;
        case 'R':
          p=a,  q=c,  r=7-b; break;
        case 'N':
          p=b,  q=7-a,r=c;   break;
        case 'S':
          p=7-b,q=a,  r=c;   break;
        case 'E':
          p=7-c,q=b,  r=a;   break;
        case 'W':
          p=c,  q=b,  r=7-a; break;
      }
      a=p,b=q,c=r;x+=a;
    }
  }
  return 0;
}
