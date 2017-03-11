main(i,n,a,b,x,y){
  for(;~scanf("%d",&n)&&n;printf("%d %d\n",a,b)){
    for(a=b=i=0;i<n;i++){
      scanf("%d%d",&x,&y);
      if(x>y)a+=x+y;
      else if(x<y)b+=x+y;
      else a+=x,b+=x;
    }
  }
  return 0;
}
