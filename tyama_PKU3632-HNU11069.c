main(n,x,s,ma,mi){
  scanf("%d",&n);
  for(;n;n--){
    scanf("%d",&x);
    mi=99;ma=0;
    for(;x;x--){
      scanf("%d", &s);
      if(mi>s)mi=s;
      if(ma<s)ma=s;
    }
    printf("%d\n",(ma-mi)*2);
  }
}