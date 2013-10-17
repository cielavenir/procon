#define min(a,b) ((a)<(b)?(a):(b))
int b[50000],h[50000],w[50000],d[50000];
main(k,n,i,v){
  double sum,hi,lo,mid;
  for(scanf("%d",&k);k;k--){
    scanf("%d",&n);
    for(hi=lo=i=0;i<n;i++){scanf("%d%d%d%d",b+i,h+i,w+i,d+i);if(hi<b[i]+h[i])hi=b[i]+h[i];}
    scanf("%d",&v);

    sum=0;
    for(i=0;i<n;i++)if(hi>b[i])sum+=w[i]*d[i]*min(hi-b[i],h[i]);
    if(sum<v){puts("OVERFLOW");continue;}

    /*binary*/
    while(hi-lo>1e-7){
      mid=(hi+lo)/2;
      sum=0;
      for(i=0;i<n;i++)if(mid>b[i])sum+=w[i]*d[i]*min(mid-b[i],h[i]);
      if(sum<v)lo=mid;else hi=mid;
    }
    printf("%.2f\n",hi);
  }
}