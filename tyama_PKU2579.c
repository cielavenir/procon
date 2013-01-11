main(){
  char s[11],a[82];
  int x,y,i,j;
  for(;scanf("%s",s),strcmp(s,"ENDOFINPUT");){
    scanf("%d%d",&y,&x);
    gets(&i);
    for(j=0;j<y;j++){
      for(i=0;i<x;i++)
        a[j*x+i]=getchar()-'0';
      gets(&i);
    }
    gets(&i);
    for(j=0;j<y-1;j++)
      for(i=0;i<x-1;i++)
        a[j*x+i]=(a[j*x+i]+a[(j+1)*x+i]+a[j*x+i+1]+a[(j+1)*x+(i+1)])/4;
    for(j=0;j<y-1;j++){
      for(i=0;i<x-1;i++)
        putchar(a[j*x+i]+'0');
      puts("");
    }
  }
}