int a[31];
main(i,n){
  for(a[0]=a[1]=1,a[2]=2,i=3;i<31;i++)a[i]=a[i-1]+a[i-2]+a[i-3];
  for(;scanf("%d",&n),n;printf("%d\n",(a[n]+3649)/3650));
  return 0;
}