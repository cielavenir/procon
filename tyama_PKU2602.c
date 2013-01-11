int x[1000001];
main(a,b,n,i){
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&a,&b);
    x[i]=a+b;
  }
  for(i=n;i;i--)
    if(x[i]>9)x[i]-=10,x[i-1]++;
  for(i=1;i<=n;i++)
    putchar(x[i]+'0');
}