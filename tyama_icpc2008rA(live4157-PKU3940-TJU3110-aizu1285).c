int h[11];

solve(int n,int w){
  int i=0,x,m=0,k=0;
  double d=0.01;
  for(;i<n;i++){
    scanf("%d",&x);
    h[x/w]++;
    if(k<x)k=x;
  }
  for(i=0;i<11;i++)
    if(m<h[i])m=h[i];
  for(i=0;i<k/w;i++){
    d += h[i]/(double)m * (k/w-i)/(double)(k/w);
  }
  printf("%.6lf\n",d);
}

main(){
  int n,w;
  while(scanf("%d%d",&n,&w),n){
    memset(h,0,sizeof(h));
    solve(n,w);
  }
}