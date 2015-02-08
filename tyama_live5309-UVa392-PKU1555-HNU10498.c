main(){
  int a[9],f,i;
  for(;;){
    for(i=0;i<9;i++)
      if(!~scanf("%d",a+i))return 0;
    for(f=i=0;i<9;i++){
      if(!a[i])continue;
      if(f)printf(" %c ",a[i]>0?'+':'-');
      else{if(a[i]<0)printf("-");f=1;}
      if((a[i]=abs(a[i]))>1||i==8)printf("%d",a[i]);
      if(i<8)printf("x");
      if(i<7)printf("^%d",8-i);
    }
    if(!f)printf("0");
    puts("");
  }
}