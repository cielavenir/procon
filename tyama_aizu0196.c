int a[10];char z[10];
main(N,i,j,w,l,x){
  for(;scanf("%d",&N),N;){
    for(i=0;i<N;i++){
      scanf(" %c",z+i);
      for(j=w=l=0;j<N-1;j++){
        scanf("%d",&x);
        if(x==0)w++;
        if(x==1)l++;
      }
      a[i]=(w<<8)+((10-l)<<4)+10-i;
    }
    for(i=0;i<N;i++)
      for(j=0;j<N;j++)
        if(a[i]>a[j])x=a[i],a[i]=a[j],a[j]=x;
    for(i=0;i<N;i++)
      printf("%c\n",z[10-a[i]&15]);
  }
  return 0;
}