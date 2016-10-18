main(){
  int a[46],i=2;
  a[0]=0,a[1]=1;
  for(;i<46;i++)a[i]=a[i-1]+a[i-2];
  gets(&i);
  for(;~scanf("%d",&i);printf("%d\n",a[i]));
  return 0;
}