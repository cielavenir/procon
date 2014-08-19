m[100][2];main(n,p,q,r,t,u,i,x,y){
  for(scanf("%d%d%d%d%d%d",&n,&p,&q,&r,&t,&u),i=0;i<n;i++)scanf("%d%d",m[i],m[i]+1);
  for(x=i=0;i<n-1;i++){
    x+=p*(m[i][1]-m[i][0]);
    y=m[i+1][0]-m[i][1];
    if(y>t+u)x+=r*(y-t-u),y=t+u;
    if(y>t)x+=q*(y-t),y=t;
    x+=p*y;
  }
  printf("%d\n",x+p*(m[i][1]-m[i][0]));
  return 0;
}