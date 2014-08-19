int a[31];
main(i,n){
  for(a[0]=a[1]=1,i=2;i<31;i++)a[i]=a[i-1]+a[i-2];
  for(;~scanf("%d",&n);printf("%d\n",a[n]));
  return 0;
}