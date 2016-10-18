int f[58],g[58];
main(i){
  f[1]=1,g[1]=1,g[2]=0,g[3]=1;
  for(i=4;i<58;i++)g[i]=g[i-1]+g[i-3];
  for(i=2;i<58;i++)f[i]=f[i-1]+g[i-1];
  for(;~scanf("%d",&i);printf("%d\n",f[i]));
  return 0;
}