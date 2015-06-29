main(){
  int n,i=1;
  float r,x1,y1,x2,y2,xh,yh,l=0;
  scanf("%d%f",&n,&r);
  if(n==0){puts("0.00");exit(0);}
  scanf("%f%f",&x1,&y1);
  xh=x1;yh=y1;
  for(;i<n;i++){
    scanf("%f%f",&x2,&y2);
    l+=hypot(x2-x1,y2-y1);
    x1=x2;y1=y2;
  }
  l+=hypot(x1-xh,y1-yh);
  printf("%.2f",l+r*6.282);
}