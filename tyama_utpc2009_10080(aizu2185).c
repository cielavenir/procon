main(x,y,w,h,r,n,a,b){
  scanf("%d%d%d%d",&x,&y,&w,&h);
  for(r=0,scanf("%d",&n);n;n--){
    scanf("%d%d",&a,&b);
    if(x<=a&&a<=x+w && y<=b&&b<=y+h)r++;
  }
  printf("%d\n",r);
  return 0;
}