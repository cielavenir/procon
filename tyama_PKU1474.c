#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int x[100],y[100];
main(c,n,i,xM,xm,yM,ym){
  for(;scanf("%d",&n),n;printf("Floor #%d\nSurveillance is %spossible.\n\n",c++,(xm<=xM&&ym<=yM)?"":"im")){
    for(i=0;i<n;i++)scanf("%d%d",x+i,y+i);
    xm=ym=-2000000000,xM=yM=2000000000;
    if(x[n-1]==x[0]){
      if(y[n-1]<y[0])xm=max(xm,x[n-1]);else xM=min(xM,x[n-1]);
    }else{
      if(x[n-1]>x[0])ym=max(ym,y[n-1]);else yM=min(yM,y[n-1]);
    }
    for(i=0;i<n-1;i++)
      if(x[i]==x[i+1]){
        if(y[i]<y[i+1])xm=max(xm,x[i]);else xM=min(xM,x[i]);
      }else{
        if(x[i]>x[i+1])ym=max(ym,y[i]);else yM=min(yM,y[i]);
      }
  }
}