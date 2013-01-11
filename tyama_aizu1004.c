int p[10001];
main(i,j,r){
  p[0]=p[1]=1;
  for(i=2;i<10001;i++)
    if(!p[i])
      for(j=i*2;j<10001;j+=i)p[j]=1;
  for(;~scanf("%d",&j);printf("%d\n",r))
    for(r=0,i=2;i<=j;i++)
      if(!p[i]&&!p[j-i+1])r++;
  return 0;
}