char a[82];main(x,y,i,j){
  for(;scanf("%s",a),*a-'E';){
    scanf("%d%d",&y,&x);
    gets(&i);
    for(j=0;j<y;gets(&i),j++)
      for(i=0;i<x;i++)
        a[j*x+i]=getchar()-'0';
    gets(&i);
    for(j=0;j<y-1;puts(""),j++)
      for(i=0;i<x-1;i++)
        putchar((a[j*x+i]+a[(j+1)*x+i]+a[j*x+i+1]+a[(j+1)*x+(i+1)])/4+48);
  }
}