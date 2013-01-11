int p[200000],a[200000];
main(){
  int i,n,k,s,t,m;
  for(;scanf("%d",&n),n;){
    k=n/2-2,s=0,t=0,m=2000000000;
    for(i=0;i<k;i++)scanf("%d",p+i),s+=p[i],t+=p[i];
    for(;i<n;i++)scanf("%d",p+i),s+=p[i],t+=p[i],a[i]=t,t-=p[i-k];
    for(i=0;i<k;i++)t+=p[i],a[i]=t,t-=p[n-k+i];
    for(i=0;i<n;i++)if(a[i]<m)m=a[i];
    printf("%d\n",s+m);
  }
}