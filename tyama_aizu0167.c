int a[100];
main(i,j,n,r,x){
  for(;scanf("%d",&n),n;printf("%d\n",r)){
    for(i=0;i<n;i++)
      scanf("%d",a+i);
    for(r=i=0;i<n;i++)
      for(j=0;j<n-1;j++)
        if(a[j]>a[j+1])x=a[j],a[j]=a[j+1],a[j+1]=x,r++;
  }
  return 0;
}